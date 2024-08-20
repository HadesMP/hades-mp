#include <string>

#include "sdk/sdk.hpp"

sdk::client_version sdk::get_client_version() {
    static client_version version;

    if (version)
        return version;

    char procPath[MAX_PATH];
    if (GetModuleFileNameA(nullptr, procPath, MAX_PATH) == 0) {
        return version = Unknown;
    }

    std::string executableName(strrchr(procPath, '\\') + 1);

    if (executableName == "Hades2.exe")
        return version = Hades_II;
    if (executableName == "Hades.exe")
        return version = Hades_I;

    return version = Unknown;
}

static const sdk::logger Hook_Logger{"Hook"};

// note: setting 'enable' to false won't disable the hook, it is simply for distinction between install / enable.
void sdk::hook_impl(void* addr, void* detour, void** original, bool enable, const char* sig) {
    MH_STATUS s;

    if ((s = MH_Initialize()) != MH_ERROR_ALREADY_INITIALIZED && s != MH_OK) {
        Hook_Logger.error("Failed to initialize MinHook: %s", MH_StatusToString(s));
    }

    if ((s = MH_CreateHook(addr, detour, original)) != MH_OK)
        Hook_Logger.error("Failed to create hook for %s: %s", sig, MH_StatusToString(s));
    else
        Hook_Logger.debug("Created hook for %s", sig);

    if (enable && (s = MH_EnableHook(addr)) != MH_OK)
        Hook_Logger.error("Failed to enable hook for %s: %s", sig, MH_StatusToString(s));
    else
        Hook_Logger.debug("Enabled hook for %s", sig);
}