#include <cstdio>
#include <windows.h>

#include <filesystem>

#include "sdk/engine.hpp"
#include "sdk/sym/resolve.hpp"
#include "sgg/Platform/FileSystem.hpp"
#include "sgg/Platform/PlatformFile.hpp"

namespace fs = std::filesystem;

static const sdk::logger Logger{"HadesMP"};
static const sdk::logger Script_Logger{"Scripts"};

bool IsContentFolderModified_hook(uint32_t directory, bool initialValue) {
    Script_Logger.debug("Game requested to check authenticity of directory %x (initial=%s)", directory, initialValue ? "true" : "false");
    return initialValue;
}

void fsSetPathForResourceDir_hook(void* pIO, sgg::ResourceMount mount, sgg::ResourceDirectory resourceDir, const char* bundleDirectory) {
    if (resourceDir == sgg::ResourceDirectory::RD_CODE) {
        Logger.debug("Overwriting code content path to 'HadesMP/Scripts'");
        return sgg::fsSetPathForResourceDir_func(true, pIO, mount, resourceDir, "HadesMP/Scripts");
    }

    return sgg::fsSetPathForResourceDir_func(true, pIO, mount, resourceDir, bundleDirectory);
}

bool CreateStreamWithRetry_hook(sgg::ResourceDirectory resourceDir, char const* fileName, sgg::FileMode filemode, struct FileStream* pOut) {
    const bool tryHML = sgg::CreateStreamWithRetry_func(true, sgg::RD_CODE, fileName, filemode, pOut);
    return tryHML || sgg::CreateStreamWithRetry_func(true, resourceDir, fileName, filemode, pOut);
}

bool LoadScript_hook(const char* scriptName) {
    Script_Logger.debug("Game requested to load content %s", scriptName);
    return sgg::ScriptManager::Load(scriptName);
}

void load_script_overrides() {
    if (!fs::exists("../HadesMP/")) {
        MessageBoxA(nullptr, "Installation of HadesMP failed (mod folder not present).\nPlease re-download the content files and try again.", "HadesMP Error", MB_OK | MB_ICONWARNING);
    }
}

void parse_arguments() {
    int argc;
    LPWSTR const* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    std::vector<std::string> arguments;
    for (int i = 1; i < argc; i++) {
        std::wstring wide(argv[i]);
        arguments.emplace_back(wide.begin(), wide.end());
    }

    for (const auto &arg : arguments) {
        if (arg == "-hmp-debug-all") {
            sdk::logger::enable_global_level(sdk::logger::l_debug);
        }
    }
}

extern "C" __declspec(dllexport) bool APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason != DLL_PROCESS_ATTACH) return TRUE;

    SetConsoleTitle("Hades Multiplayer (Hades II)");
    Logger.info("Loading Hades multiplayer mod...");

    parse_arguments();

    sdk::add_engine_trees_to_resolver();
    sdk::sym_resolver::get()->resolve_all();

    load_script_overrides();

    try {
        sgg::ScriptManager_Load.hook(&LoadScript_hook);
        sgg::fsSetPathForResourceDir_func.hook(&fsSetPathForResourceDir_hook);
        sgg::IsContentFolderModified_func.hook(&IsContentFolderModified_hook);
    } catch (std::runtime_error &error) {
        Script_Logger.error("Hook error: %s", error.what());
    }

    return TRUE;
}