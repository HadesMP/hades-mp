//
// This file contains code which resolves various SDK tree structures from the client PDB.
//

#ifndef SDK_SYM_RESOLVE_HPP
#define SDK_SYM_RESOLVE_HPP

#include <map>
#include <vector>
#include <memory>
#include <cstdio>
#include <functional>
#include <windows.h>
#include <DbgHelp.h>

namespace sdk {
    enum sym_resolution_type {
        struct_t,
        struct_field_t,
        struct_func_t,
        global_field_t,
        global_func_t
    };

    struct sym_resolution_data {
        using shared_ptr = std::shared_ptr<sym_resolution_data>;
        using vector = std::vector<shared_ptr>;

        sym_resolution_type mType{};
        std::string mStructName{};
        std::string mMemberName{};
        bool mResolved;
        void* mSymPointer;
    };

    union sym_resolution_result {
        size_t mSize;
        uintptr_t mAddr;
        ptrdiff_t mOffset;
    };

    class sym_resolver {
    private:
        HANDLE mProcessHandle{};
        DWORD64 mBaseAddress{};
        std::map<void*, sym_resolution_result> mResolvedData{};
        std::map<std::string, sym_resolution_data::vector> mSymbols{};
        std::map<std::string, sym_resolution_data::shared_ptr> mGlobalSymbols{};

    protected:
        sym_resolver();

        ~sym_resolver();

    private:
        bool get_type_info(ULONG TypeId, _IMAGEHLP_SYMBOL_TYPE_INFO GetType, PVOID pInfo);

        bool get_type_info(PSYMBOL_INFO pSymInfo, _IMAGEHLP_SYMBOL_TYPE_INFO GetType, PVOID pInfo);

        bool type_enum_callback(PSYMBOL_INFO pSymInfo, ULONG SymbolSize);

        bool symbol_enum_callback(PSYMBOL_INFO pSymInfo, ULONG SymbolSize);

    public:
        void add_data(const sym_resolution_data::shared_ptr &data);

        void add_global_data(const sym_resolution_data::shared_ptr &data);

        sym_resolution_result get_data(void* symAddr);

        void resolve_all();

    public:
        static sym_resolver *const &get() {
            static sym_resolver *instance;
            return instance == nullptr ? (instance = new sym_resolver()) : instance;
        }
    };
}

#endif //SDK_SYM_RESOLVE_HPP
