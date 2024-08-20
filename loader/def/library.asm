extern orig_GetFileVersionInfoA: DQ
extern orig_GetFileVersionInfoByHandle: DQ
extern orig_GetFileVersionInfoExA: DQ
extern orig_GetFileVersionInfoExW: DQ
extern orig_GetFileVersionInfoSizeA: DQ
extern orig_GetFileVersionInfoSizeExA: DQ
extern orig_GetFileVersionInfoSizeExW: DQ
extern orig_GetFileVersionInfoSizeW: DQ
extern orig_GetFileVersionInfoW: DQ
extern orig_VerFindFileA: DQ
extern orig_VerFindFileW: DQ
extern orig_VerInstallFileA: DQ
extern orig_VerInstallFileW: DQ
extern orig_VerLanguageNameA: DQ
extern orig_VerLanguageNameW: DQ
extern orig_VerQueryValueA: DQ
extern orig_VerQueryValueW: DQ

.code

_GetFileVersionInfoA proc
        jmp orig_GetFileVersionInfoA
_GetFileVersionInfoA endp

_GetFileVersionInfoByHandle proc
        jmp orig_GetFileVersionInfoByHandle
_GetFileVersionInfoByHandle endp

_GetFileVersionInfoExA proc
        jmp orig_GetFileVersionInfoExA
_GetFileVersionInfoExA endp

_GetFileVersionInfoExW proc
        jmp orig_GetFileVersionInfoExW
_GetFileVersionInfoExW endp

_GetFileVersionInfoSizeA proc
        jmp orig_GetFileVersionInfoSizeA
_GetFileVersionInfoSizeA endp

_GetFileVersionInfoSizeExA proc
        jmp orig_GetFileVersionInfoSizeExA
_GetFileVersionInfoSizeExA endp

_GetFileVersionInfoSizeExW proc
        jmp orig_GetFileVersionInfoSizeExW
_GetFileVersionInfoSizeExW endp

_GetFileVersionInfoSizeW proc
        jmp orig_GetFileVersionInfoSizeW
_GetFileVersionInfoSizeW endp

_GetFileVersionInfoW proc
        jmp orig_GetFileVersionInfoW
_GetFileVersionInfoW endp

_VerFindFileA proc
        jmp orig_VerFindFileA
_VerFindFileA endp

_VerFindFileW proc
        jmp orig_VerFindFileW
_VerFindFileW endp

_VerInstallFileA proc
        jmp orig_VerInstallFileA
_VerInstallFileA endp

_VerInstallFileW proc
        jmp orig_VerInstallFileW
_VerInstallFileW endp

_VerLanguageNameA proc
        jmp orig_VerLanguageNameA
_VerLanguageNameA endp

_VerLanguageNameW proc
        jmp orig_VerLanguageNameW
_VerLanguageNameW endp

_VerQueryValueA proc
        jmp orig_VerQueryValueA
_VerQueryValueA endp

_VerQueryValueW proc
        jmp orig_VerQueryValueW
_VerQueryValueW endp

end