#include <windows.h>
#include <corecrt_io.h>

#include <ios>
#include <filesystem>

#include "sdk/sdk.hpp"
#include "sdk/logger.hpp"
#include "loader/library.h"

namespace fs = std::filesystem;

static const auto MODS_DIR = "../Mods/";
static const auto VERSION = "1.0.0";

static sdk::logger Logger{"HML"};
static sdk::logger Mods_Logger{"Mods"};

struct {
    bool trust_unsigned_mods = false;
} options;

void create_and_attach_console() {
    if (!AllocConsole()) return;

    FILE *f;

    if (freopen_s(&f, "CONOUT$", "w", stdout))
        _dup2(_fileno(stdout), 1);

    if (freopen_s(&f, "CONOUT$", "w", stderr))
        _dup2(_fileno(stdout), 2);

    std::ios::sync_with_stdio();

    SetConsoleTitle("Hades Mod Loader");
}

void parse_arguments() {
    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    std::vector<std::string> arguments;
    for (int i = 1; i < argc; i++) {
        std::wstring wide(argv[i]);
        arguments.emplace_back(wide.begin(), wide.end());
    }

    for (const auto &arg : arguments) {
        if (arg == "-hml-debug-all") {
            sdk::logger::enable_global_level(sdk::logger::l_debug);
        }
        if (arg == "-hml-debug-mods") {
            Mods_Logger.enable_level(sdk::logger::l_debug);
        }
        if (arg == "-hml-trust-unsigned-mods") {
            options.trust_unsigned_mods = true;
        }
    }
}

void find_and_load_mods() {
    if (!fs::exists(MODS_DIR)) {
        Logger.warn("Mods folder was not found.");
        return;
    }

    if (!fs::is_directory(MODS_DIR)) {
        Logger.error("Mods folder is not a directory.");
        return;
    }
}

extern "C" __declspec(dllexport) bool APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason != DLL_PROCESS_ATTACH) return TRUE;

    if (sdk::get_client_version() != sdk::Unknown) {
        library_init();
        create_and_attach_console();

        Logger.info("Hades mod loader version %s", VERSION);

        if (fs::exists("hades-mp.dll")) {
            Logger.warn("Hades multiplayer mod was found.");
            Logger.warn("It is currently incompatiable with other mods, so no other mods will be loaded.");
            if (!LoadLibraryA("hades-mp.dll")) {
                Logger.warn("Could not load hades multiplayer mod...");
            }
        }
        else {
            Logger.info("Starting as normal mod loader client...");
            find_and_load_mods();
        }
    }

    return TRUE;
}