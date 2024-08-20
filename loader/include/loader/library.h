#include <windows.h>

#ifndef VERSION_PROXY_H
#define VERSION_PROXY_H

extern "C" {
FARPROC orig_GetFileVersionInfoA;
FARPROC orig_GetFileVersionInfoByHandle;
FARPROC orig_GetFileVersionInfoExA;
FARPROC orig_GetFileVersionInfoExW;
FARPROC orig_GetFileVersionInfoSizeA;
FARPROC orig_GetFileVersionInfoSizeExA;
FARPROC orig_GetFileVersionInfoSizeExW;
FARPROC orig_GetFileVersionInfoSizeW;
FARPROC orig_GetFileVersionInfoW;
FARPROC orig_VerFindFileA;
FARPROC orig_VerFindFileW;
FARPROC orig_VerInstallFileA;
FARPROC orig_VerInstallFileW;
FARPROC orig_VerLanguageNameA;
FARPROC orig_VerLanguageNameW;
FARPROC orig_VerQueryValueA;
FARPROC orig_VerQueryValueW;
}

#define WRAPPER_FUNC(name) orig_##name = GetProcAddress(hOriginalDll, #name);

void library_init() {
    char source[MAX_PATH];
    GetSystemDirectory(source, MAX_PATH);
    strcat_s(source, sizeof source, "\\version.dll");
    HMODULE hOriginalDll = LoadLibrary(source);

    WRAPPER_FUNC(GetFileVersionInfoA)
    WRAPPER_FUNC(GetFileVersionInfoByHandle)
    WRAPPER_FUNC(GetFileVersionInfoExW)
    WRAPPER_FUNC(GetFileVersionInfoExA)
    WRAPPER_FUNC(GetFileVersionInfoSizeA)
    WRAPPER_FUNC(GetFileVersionInfoSizeExW)
    WRAPPER_FUNC(GetFileVersionInfoSizeExA)
    WRAPPER_FUNC(GetFileVersionInfoSizeW)
    WRAPPER_FUNC(GetFileVersionInfoW)
    WRAPPER_FUNC(VerFindFileA)
    WRAPPER_FUNC(VerFindFileW)
    WRAPPER_FUNC(VerInstallFileA)
    WRAPPER_FUNC(VerInstallFileW)
    WRAPPER_FUNC(VerLanguageNameA)
    WRAPPER_FUNC(VerLanguageNameW)
    WRAPPER_FUNC(VerQueryValueA)
    WRAPPER_FUNC(VerQueryValueW)
}

#endif // VERSION_PROXY_H