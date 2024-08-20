#ifndef SDK_SDK_HPP
#define SDK_SDK_HPP

#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

#include "logger.hpp"

#include "minhook/MinHook.h"

#pragma comment(lib, "libMinHook.x64.lib")

#define concat(a, b)         _concat_impl(a,b)
#define concat_impl(a, b)   a##b
#define pad(x) char concat(pad_, __COUNTER__) [x];

#define getter(field, name) \
decltype(field)::value_type name() const { return field.get(this); }

#define setter(field, name) \
void name(decltype(field)::value_type value) const { field.set(this, value); }

#define getter_and_setter(field, name) \
getter(field, name); setter(field, name)

namespace sdk {
    static const sdk::logger SDK_Logger {"SDK"};

    enum client_version {
        Unknown = 1,
        Hades_I,
        Hades_II,
    };

    client_version get_client_version();

    void hook_impl(void *addr, void *detour, void **orig, bool enable, const char *sig);
} // namespace sdk

#endif // SDK_SDK_HPP
