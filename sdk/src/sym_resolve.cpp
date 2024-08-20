#include <array>

#include "sdk/sdk.hpp"
#include "sdk/sym/resolve.hpp"

#include <string>

#include <dbghelp.h>
#include <span>

#pragma comment(lib, "Dbghelp.lib")

static const sdk::logger Logger{"Symbols"};

void PrintLastError(const char *prefix) {
    DWORD errorCode = GetLastError();
    LPSTR messageBuffer = nullptr;

    size_t size = FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr,
            errorCode,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR) &messageBuffer, 0, nullptr
    );
    std::string errorMessage(messageBuffer, size - 1);

    LocalFree(messageBuffer);

    Logger.error("(%s) %lu: %s", prefix, errorCode, errorMessage.c_str());
}

sdk::sym_resolver::sym_resolver() {
    mProcessHandle = GetCurrentProcess();

    SymSetOptions(SYMOPT_ALLOW_ABSOLUTE_SYMBOLS | SYMOPT_NO_PROMPTS | SYMOPT_UNDNAME | SYMOPT_LOAD_ANYTHING);
    SymInitialize(mProcessHandle, nullptr, true);

    const auto isHades2 = sdk::get_client_version() == sdk::Hades_II;
    mBaseAddress = (DWORD64) GetModuleHandle(isHades2 ? nullptr : "EngineWin64s.dll");

    auto result = SymLoadModule64(mProcessHandle, nullptr, isHades2 ? "Hades2.exe" : "EngineWin64s.dll", nullptr,
                                  mBaseAddress, 0);

    if (result == 0 && GetLastError() != ERROR_SUCCESS) {
        PrintLastError("Init/SymLoadModuleEx");
        return;
    }

    IMAGEHLP_MODULE64 moduleInfo64;
    moduleInfo64.SizeOfStruct = sizeof(moduleInfo64);
    if (SymGetModuleInfo64(mProcessHandle, mBaseAddress, &moduleInfo64)) {
        Logger.debug("Loaded the debug symbol table from %s", moduleInfo64.LoadedPdbName);
    } else {
        PrintLastError("Init/SymGetModuleInfo64");
        return;
    }
}

enum SymTagEnum {
    SymTagNull,
    SymTagExe,
    SymTagCompiland,
    SymTagCompilandDetails,
    SymTagCompilandEnv,
    SymTagFunction,
    SymTagBlock,
    SymTagData,
    SymTagAnnotation,
    SymTagLabel,
    SymTagPublicSymbol,
    SymTagUDT,
    SymTagEnum,
    SymTagFunctionType,
    SymTagPointerType,
    SymTagArrayType,
    SymTagBaseType,
    SymTagTypedef,
    SymTagBaseClass,
    SymTagFriend,
    SymTagFunctionArgType,
    SymTagFuncDebugStart,
    SymTagFuncDebugEnd,
    SymTagUsingNamespace,
    SymTagVTableShape,
    SymTagVTable,
    SymTagCustom,
    SymTagThunk,
    SymTagCustomType,
    SymTagManagedType,
    SymTagDimension,
    SymTagCallSite,
    SymTagInlineSite,
    SymTagBaseInterface,
    SymTagVectorType,
    SymTagMatrixType,
    SymTagHLSLType
};

bool sdk::sym_resolver::get_type_info(PSYMBOL_INFO pSymInfo, _IMAGEHLP_SYMBOL_TYPE_INFO GetType, PVOID pInfo) {
    return ::SymGetTypeInfo(mProcessHandle, mBaseAddress, pSymInfo->TypeIndex, GetType, pInfo);
}

bool sdk::sym_resolver::get_type_info(ULONG TypeId, _IMAGEHLP_SYMBOL_TYPE_INFO GetType, PVOID pInfo) {
    return ::SymGetTypeInfo(mProcessHandle, mBaseAddress, TypeId, GetType, pInfo);
}

void sdk::sym_resolver::add_data(const sym_resolution_data::shared_ptr &data) {
    mResolvedData[data->mSymPointer] = {};
    mSymbols[data->mStructName].emplace_back(data);
}

void sdk::sym_resolver::add_global_data(const sym_resolution_data::shared_ptr &data) {
    mGlobalSymbols[data->mMemberName] = data;
}

sdk::sym_resolution_result sdk::sym_resolver::get_data(void *symAddr) {
    return mResolvedData.contains(symAddr) ? mResolvedData.at(symAddr) : sym_resolution_result{};
}

bool sdk::sym_resolver::type_enum_callback(PSYMBOL_INFO pSymInfo, ULONG SymbolSize) {
    if (pSymInfo->Tag != SymTagUDT || !pSymInfo->NameLen || !mSymbols.count(pSymInfo->Name))
        return TRUE;

    ULONG count;
    if (!get_type_info(pSymInfo, TI_GET_CHILDRENCOUNT, &count)) {
        Logger.error("Could not get children count of %s", pSymInfo->Name);
        PrintLastError("TI_GET_CHILDRENCOUNT");
        return TRUE;
    }

    if (count == 0)
        return TRUE;

    auto childrenPtr = std::make_unique<uint8_t[]>(sizeof(_TI_FINDCHILDREN_PARAMS) + ((count - 1) * sizeof(ULONG)));
    auto children = (_TI_FINDCHILDREN_PARAMS *) childrenPtr.get();
    children->Start = 0;
    children->Count = count;

    if (!get_type_info(pSymInfo, TI_FINDCHILDREN, children)) {
        Logger.error("Could not get children of %s", pSymInfo->Name);
        PrintLastError("TI_FINDCHILDREN");
        return TRUE;
    }

    auto list = mSymbols.at(pSymInfo->Name);
    for (const auto &item: list) {
        if (item->mType == struct_t && !item->mResolved) {
            item->mResolved = true;
            mResolvedData[item->mSymPointer] = sym_resolution_result{.mSize = size_t(SymbolSize)};
            break;
        }
    }

    for (ULONG i = 0; i < children->Count; ++i) {
        ULONG childId = children->ChildId[i];
        WCHAR *childName;
        ULONG childTag;

        if (!get_type_info(childId, TI_GET_SYMNAME, &childName)) {
            LocalFree(childName);
            Logger.error("Could not get symbol name for child %i of %s", i, pSymInfo->Name);
            PrintLastError("TI_GET_SYMNAME");
            continue;
        }

        if (!get_type_info(childId, TI_GET_SYMTAG, &childTag)) {
            LocalFree(childName);
            Logger.error("Could not get symbol tag for child %ls of %s", childName, pSymInfo->Name);
            PrintLastError("TI_GET_SYMTAG");
            continue;
        }

        std::wstring wideChildName(childName);
        std::string memberName(wideChildName.begin(), wideChildName.end());

        LocalFree(childName);

        if (childTag == SymTagData) {
            ULONG64 offset;
            if (!get_type_info(childId, TI_GET_OFFSET, &offset)) {
                //Logger.debug("Error getting offset for field %s of %s", memberName.c_str(), pSymInfo->Name);
                //PrintLastError("TI_GET_OFFSET");
                continue;
            }

            for (const auto &item: list) {
                if (item->mType == sym_resolution_type::struct_field_t && memberName == item->mMemberName &&
                    !item->mResolved) {
                    item->mResolved = true;
                    mResolvedData[item->mSymPointer] = sym_resolution_result{.mOffset = ptrdiff_t(offset)};

                    Logger.debug("Resolved %s::%s at offset %x", pSymInfo->Name, memberName.c_str(),
                                 offset);

                    break;
                }
            }
        }

        if (childTag == SymTagFunction) {
            ULONG64 address;
            if (!get_type_info(childId, TI_GET_ADDRESS, &address)) {
                //Logger.debug("Error getting address for function %s of %s", memberName.c_str(), pSymInfo->Name);
                //PrintLastError("TI_GET_ADDRESS");
                continue;
            }

            for (const auto &item: list) {
                if (item->mType == sym_resolution_type::struct_func_t && memberName == item->mMemberName &&
                    !item->mResolved) {
                    item->mResolved = true;
                    mResolvedData[item->mSymPointer] = sym_resolution_result{.mAddr = uintptr_t(address)};

                    Logger.debug("Resolved of %s::%s at address %llx", pSymInfo->Name,
                                 memberName.c_str(),
                                 address);

                    break;
                }
            }
        }
    }

    return TRUE;
}

bool sdk::sym_resolver::symbol_enum_callback(PSYMBOL_INFO pSymInfo, ULONG SymbolSize) {
    if ((pSymInfo->Tag == SymTagFunction || pSymInfo->Tag == SymTagData || pSymInfo->Tag == SymTagPublicSymbol) && mGlobalSymbols.count(pSymInfo->Name)) {
        auto item = mGlobalSymbols.at(pSymInfo->Name);
        if (item->mResolved) return TRUE;

        auto address = pSymInfo->Address;

        item->mResolved = true;
        mResolvedData[item->mSymPointer] = sym_resolution_result{.mAddr = uintptr_t(address)};

        Logger.debug("Resolved global %s at address %llx", pSymInfo->Name, address);
    }

    return TRUE;
}


void sdk::sym_resolver::resolve_all() {
    SymEnumTypes(mProcessHandle, mBaseAddress, [](
            PSYMBOL_INFO pSymInfo,
            ULONG SymbolSize,
            PVOID UserContext
    ) -> BOOL {
        sym_resolver::get()->type_enum_callback(pSymInfo, SymbolSize);
        return TRUE;
    }, nullptr);

    SymEnumSymbols(mProcessHandle, mBaseAddress, "*", [](
            PSYMBOL_INFO pSymInfo,
            ULONG SymbolSize,
            PVOID UserContext
    ) -> BOOL {
        sym_resolver::get()->symbol_enum_callback(pSymInfo, SymbolSize);
        return TRUE;
    }, nullptr);
}

sdk::sym_resolver::~sym_resolver() {
    SymUnloadModule64(mProcessHandle, mBaseAddress);
    SymCleanup(mProcessHandle);
}