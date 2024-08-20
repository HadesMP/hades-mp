//
// This file contains code which defines the various SDK symbol tree structures,
// Such as structure wrappers, fields (members) & functions.
// In order to use one of these wrappers, it must first be resolved.
//

#ifndef SDK_SYM_DEFS_HPP
#define SDK_SYM_DEFS_HPP

#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

#include "resolve.hpp"
#include "sdk/sdk.hpp"
#include "sdk/logger.hpp"

namespace sdk {
    template<auto N>
    struct string_literal {
        constexpr string_literal(const char (&str)[N]) { std::copy(str, str + N, value); }

        char value[N]{};
    };

    template<string_literal sig, typename value_t>
    struct pdb_global_field {
        using value_type = value_t;

        constexpr explicit pdb_global_field() {
            std::copy(sig.value, sig.value + sizeof(sig), mSignature);
        };

        ~pdb_global_field() = default;

        value_t get() const {
            if (!addr()) {
                SDK_Logger.error("Attempted to get global %s but it had not been resolved!", mSignature);
                throw std::runtime_error("Symbol not resolved");
            }
            return *(value_t *) (addr());
        }

        void set(value_t value) const {
            if (!addr()) {
                SDK_Logger.error("Attempted to set global %s but it had not been resolved!", mSignature);
                throw std::runtime_error("Symbol not resolved");
            }
            *(value_t *) (addr()) = value;
        }

        uintptr_t addr() const {
            static uintptr_t addr = sym_resolver::get()->get_data((void *) this).mAddr;
            return addr;
        }

        char mSignature[sizeof(sig)]{};
    };

    template<string_literal sig, typename return_t>
    struct pdb_global_func {
        using return_type = return_t;
        using variadic_function_pointer_type = return_type (*)(...);

        constexpr explicit pdb_global_func() {
            std::copy(sig.value, sig.value + sizeof(sig), mSignature);
        };

        ~pdb_global_func() = default;

        return_type operator()(bool original = true, auto... args) const {
            if (!addr()) {
                SDK_Logger.error("Attempted to invoke global %s but it had not been resolved!", mSignature);
                throw std::runtime_error("Symbol not resolved");
            }

            return ((variadic_function_pointer_type) (original ? mOrigAddr : addr()))(args...);
        }

        void hook(void *detour, bool enable = true) const {
            if (!addr()) {
                SDK_Logger.error("Attempted to hook global %s but it had not been resolved!", mSignature);
                throw std::runtime_error("Symbol not resolved");
            }

            return hook_impl((void *) addr(), detour, (void **) &mOrigAddr, enable, mSignature);
        }

        uintptr_t addr() const {
            static uintptr_t addr = sym_resolver::get()->get_data((void *) this).mAddr;
            return addr;
        }

        mutable uintptr_t mOrigAddr{};
        char mSignature[sizeof(sig)]{};
    };

    /**
     * @tparam value_t the (C) structure which holds the SDK helper functions.
     * @tparam sig the signature of the structure
     */
    template<typename value_t, string_literal sig>
    struct pdb_struct {
        using value_type = value_t;

        constexpr explicit pdb_struct() {
            std::copy(sig.value, sig.value + sizeof(sig), mSignature);
        };

        ~pdb_struct() = default;

        size_t size() const {
            static size_t size = sym_resolver::get()->get_data((void *) this).mSize;
            return size;
        }

        char mSignature[sizeof(sig)]{};
    };

    // todo: constructor and destructor wrapping
    template<const pdb_struct parent>
    struct struct_wrapper {
        //void *operator new(size_t _) {
        //    //static_assert(sizeof(back_t<parent>) == 0);
        //    auto mem = malloc(parent.size());
        //    return mem;
        //}

        //void operator delete(void *mem) {
        //    //static_assert(sizeof(back_t<parent>) == 0);
        //    free(mem);
        //}
    };

    template<pdb_struct parent_t, string_literal sig, typename value_t>
    struct pdb_struct_field {
        using value_type = value_t;
        using parent_struct_type = decltype(parent_t);
        using parent_struct_value_type = typename parent_struct_type::value_type;

        constexpr explicit pdb_struct_field() {
            std::copy(sig.value, sig.value + sizeof(sig), mSignature);
        };

        ~pdb_struct_field() = default;

        ptrdiff_t offset() const {
            static ptrdiff_t offset = sym_resolver::get()->get_data((void *) this).mOffset;
            return offset;
        }

        value_t get(const parent_struct_value_type *_this) const {
            if (!offset()) {
                SDK_Logger.error("Attempted to get %s::%s but it had not been resolved!", parent_t.mSignature,
                                 mSignature);
                throw std::runtime_error("Symbol not resolved");
            }
            return *(value_t *) (_this + offset());
        }

        template<pdb_struct struct_t>
        typename decltype(struct_t)::value_type *get(const parent_struct_value_type *_this) const {
            if (!offset()) {
                SDK_Logger.error("Attempted to get %s::%s has not been resolved!", parent_t.mSignature, mSignature);
                throw std::runtime_error("Symbol not resolved");
            }
            return (value_t *) (_this + offset());
        }

        void set(const parent_struct_value_type *_this, value_t value) const {
            if (!offset()) {
                SDK_Logger.error("Attempted to set %s::%s but it had not been resolved!", parent_t.mSignature,
                                 mSignature);
                throw std::runtime_error("Symbol not resolved");
            }
            *(value_t *) (_this + offset()) = value;
        }

        char mSignature[sizeof(sig)]{};
    };

    template<pdb_struct parent_t, string_literal sig, typename return_t>
    struct pdb_struct_func {
        using return_type = return_t;
        using parent_struct_type = decltype(parent_t);
        using parent_struct_value_type = typename parent_struct_type::value_type;
        using variadic_function_pointer_type = return_type (*)(...);
        using variadic_member_function_pointer_type = return_type (*)(parent_struct_value_type *, ...);

        constexpr explicit pdb_struct_func() {
            std::copy(sig.value, sig.value + sizeof(sig), mSignature);
        };

        ~pdb_struct_func() = default;

        return_type operator()(bool original = true, auto... args) const {
            if (!addr()) {
                SDK_Logger.error("Attempted to invoke %s::%s but it had not been resolved!", parent_t.mSignature,
                                 mSignature);
                throw std::runtime_error("Symbol not resolved");
            }

            return ((variadic_function_pointer_type) (original ? mOrigAddr : addr()))(args...);
        }

        void hook(void *detour, bool enable = true) const {
            if (!addr()) {
                SDK_Logger.error("Attempted to hook %s::%s but it had not been resolved!", parent_t.mSignature,
                                 mSignature);
                throw std::runtime_error("Symbol not resolved");
            }

            auto formattedName = std::string(parent_t.mSignature) + "::" + mSignature;

            return hook_impl((void *) addr(), detour, (void **) &mOrigAddr, enable, formattedName.c_str());
        }

        uintptr_t addr() const {
            static uintptr_t addr = sym_resolver::get()->get_data((void *) this).mAddr;
            return addr;
        }

        mutable uintptr_t mOrigAddr{};
        char mSignature[sizeof(sig)]{};
    };

    template<typename>
    struct is_pdb_global_field : std::false_type {
    };

    template<string_literal sig, typename value_t>
    struct is_pdb_global_field<pdb_global_field<sig, value_t>> : std::true_type {
    };

    template<typename>
    struct is_pdb_global_func : std::false_type {
    };

    template<string_literal sig, typename return_t>
    struct is_pdb_global_func<pdb_global_func<sig, return_t>> : std::true_type {
    };

    template<typename>
    struct is_pdb_struct : std::false_type {
    };

    template<typename value_t, string_literal sig>
    struct is_pdb_struct<pdb_struct<value_t, sig>> : std::true_type {
    };

    template<typename>
    struct is_pdb_struct_field : std::false_type {
    };

    template<pdb_struct parent_t, string_literal sig, typename value_t>
    struct is_pdb_struct_field<pdb_struct_field<parent_t, sig, value_t>> : std::true_type {
    };

    template<typename>
    struct is_pdb_struct_func : std::false_type {
    };

    template<pdb_struct parent_t, string_literal sig, typename return_t>
    struct is_pdb_struct_func<pdb_struct_func<parent_t, sig, return_t>> : std::true_type {
    };

    template<typename... syms_t>
    struct pdb_sym_tree {
        explicit pdb_sym_tree(syms_t &&... symbols) {
            process_arguments(std::forward<syms_t>(symbols)...);
        };

        ~pdb_sym_tree() = default;

        void add_to_resolver() const {
            for (const auto &data: mSymbols) {
                sym_resolver::get()->add_data(data);
            }

            for (const auto &data: mGlobalSymbols) {
                sym_resolver::get()->add_global_data(data);
            }
        }

    private:
        sym_resolution_data::vector mSymbols{};
        sym_resolution_data::vector mGlobalSymbols{};

        template<typename arg_t, typename... rest_t>
        void process_arguments(arg_t &&arg, rest_t &&... rest) {
            using decayed_t = std::decay_t<std::remove_pointer_t<arg_t>>;

            if constexpr (is_pdb_global_field<decayed_t>::value) {
                process_global_field(*std::forward<arg_t>(arg));
            } else if constexpr (is_pdb_global_func<decayed_t>::value) {
                process_global_func(*std::forward<arg_t>(arg));
            } else if constexpr (is_pdb_struct<decayed_t>::value) {
                process_struct(*std::forward<arg_t>(arg));
            } else if constexpr (is_pdb_struct_field<decayed_t>::value) {
                process_struct_field(*std::forward<arg_t>(arg));
            } else if constexpr (is_pdb_struct_func<decayed_t>::value) {
                process_struct_func(*std::forward<arg_t>(arg));
            }

            if constexpr (sizeof...(rest_t) > 0) {
                process_arguments(std::forward<rest_t>(rest)...);
            }
        }

        template<string_literal sig, typename value_t>
        void process_global_field(const pdb_global_field<sig, value_t> &global_field) {
            SDK_Logger.debug("Added global field %s to resolution context", global_field.mSignature);

            std::string memberName{};
            memberName.assign(global_field.mSignature);

            sym_resolution_data data{
                    .mType = global_field_t,
                    .mStructName = {},
                    .mMemberName = memberName,
                    .mSymPointer = (void *) &global_field
            };

            mGlobalSymbols.push_back(std::make_unique<sym_resolution_data>(data));
        }

        template<string_literal sig, typename return_t>
        void process_global_func(const pdb_global_func<sig, return_t> &global_func) {
            SDK_Logger.debug("Added global function %s to resolution context", global_func.mSignature);

            std::string memberName{};
            memberName.assign(global_func.mSignature);

            sym_resolution_data data{
                    .mType = global_func_t,
                    .mStructName = {},
                    .mMemberName = memberName,
                    .mSymPointer = (void *) &global_func
            };

            mGlobalSymbols.push_back(std::make_unique<sym_resolution_data>(data));
        }


        template<typename value_t, string_literal sig>
        void process_struct(const pdb_struct <value_t, sig> &pdb_struct) {
            SDK_Logger.debug("Added struct %s to resolution context", pdb_struct.mSignature);

            std::string structName{};
            structName.assign(pdb_struct.mSignature);

            sym_resolution_data data{
                    .mType = struct_t,
                    .mStructName = structName,
                    .mMemberName = {},
                    .mSymPointer = (void *) &pdb_struct
            };

            mSymbols.push_back(std::make_unique<sym_resolution_data>(data));
        }

        template<pdb_struct parent_t, string_literal sig, typename value_t>
        void process_struct_field(const pdb_struct_field<parent_t, sig, value_t> &pdb_field) {
            SDK_Logger.debug("Added struct field %s::%s to resolution context", parent_t.mSignature,
                             pdb_field.mSignature);

            std::string structName{};
            structName.assign(parent_t.mSignature);

            std::string memberName{};
            memberName.assign(pdb_field.mSignature);

            sym_resolution_data data{
                    .mType = struct_field_t,
                    .mStructName = structName,
                    .mMemberName = memberName,
                    .mSymPointer = (void *) &pdb_field
            };

            mSymbols.push_back(std::make_unique<sym_resolution_data>(data));
        }

        template<pdb_struct parent_t, string_literal sig, typename return_t>
        void process_struct_func(const pdb_struct_func<parent_t, sig, return_t> &pdb_func) {
            SDK_Logger.debug("Added struct function %s::%s to resolution context", parent_t.mSignature,
                             pdb_func.mSignature);

            std::string structName{};
            structName.assign(parent_t.mSignature);

            std::string memberName{};
            memberName.assign(pdb_func.mSignature);

            sym_resolution_data data{
                    .mType = struct_func_t,
                    .mStructName = structName,
                    .mMemberName = memberName,
                    .mSymPointer = (void *) &pdb_func
            };

            mSymbols.push_back(std::make_unique<sym_resolution_data>(data));
        }
    };
}

#endif //SDK_SYM_DEFS_HPP
