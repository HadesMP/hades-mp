#ifndef SDK_LUA
#define SDK_LUA

#include "lauxlib.h"
#include "lua/lua.h"
#include "sdk/sym/defs.hpp"

/*
** state manipulation
*/
static constexpr sdk::pdb_global_func<"lua_newstate", lua_State *> lua_newstate_func;
static constexpr sdk::pdb_global_func<"lua_close", void> lua_close_func;
static constexpr sdk::pdb_global_func<"lua_newstate", lua_State *> lua_newthread_func;
static constexpr sdk::pdb_global_func<"lua_atpanic", lua_CFunction> lua_atpanic_func;
static constexpr sdk::pdb_global_func<"lua_version", lua_Number *> lua_version_func;

LUA_API lua_State *(lua_newstate)(lua_Alloc f, void *ud) {
    return lua_newstate_func(true, f, ud);
}

LUA_API void (lua_close)(lua_State *L) {
    return lua_close_func(true, L);
}

LUA_API lua_State *(lua_newthread)(lua_State *L) {
    return lua_newthread_func(true, L);
}

LUA_API lua_CFunction (lua_atpanic)(lua_State *L, lua_CFunction panicf) {
    return lua_atpanic_func(true, L, panicf);
}

LUA_API const lua_Number *(lua_version)(lua_State *L) {
    return lua_version_func(true, L);
}

/*
** basic stack manipulation
*/
static constexpr sdk::pdb_global_func<"lua_absindex", int> lua_absindex_func;
static constexpr sdk::pdb_global_func<"lua_gettop", int> lua_gettop_func;
static constexpr sdk::pdb_global_func<"lua_settop", void> lua_settop_func;
static constexpr sdk::pdb_global_func<"lua_pushvalue", void> lua_pushvalue_func;
static constexpr sdk::pdb_global_func<"lua_remove", void> lua_remove_func;
static constexpr sdk::pdb_global_func<"lua_insert", void> lua_insert_func;
static constexpr sdk::pdb_global_func<"lua_replace", void> lua_replace_func;
static constexpr sdk::pdb_global_func<"lua_copy", void> lua_copy_func;
static constexpr sdk::pdb_global_func<"lua_checkstack", int> lua_checkstack_func;
static constexpr sdk::pdb_global_func<"lua_xmove", void> lua_xmove_func;

LUA_API int (lua_absindex)(lua_State *L, int idx) {
    return lua_absindex_func(true, L, idx);
}

LUA_API int (lua_gettop)(lua_State *L) {
    return lua_gettop_func(true, L);
}

LUA_API void (lua_settop)(lua_State *L, int idx) {
    return lua_settop_func(true, L, idx);
}

LUA_API void (lua_pushvalue)(lua_State *L, int idx) {
    return lua_pushvalue_func(true, L, idx);
}

LUA_API void (lua_remove)(lua_State *L, int idx) {
    return lua_remove_func(true, L, idx);
}

LUA_API void (lua_insert)(lua_State *L, int idx) {
    return lua_insert_func(true, L, idx);
}

LUA_API void (lua_replace)(lua_State *L, int idx) {
    return lua_replace_func(true, L, idx);
}

LUA_API void (lua_copy)(lua_State *L, int fromidx, int toidx) {
    return lua_copy_func(true, L, fromidx, toidx);
}

LUA_API int (lua_checkstack)(lua_State *L, int sz) {
    return lua_checkstack_func(true, L, sz);
}

LUA_API void (lua_xmove)(lua_State *from, lua_State *to, int n) {
    return lua_xmove_func(true, from, to, n);
}

/*
** access functions (stack -> C)
*/
static constexpr sdk::pdb_global_func<"lua_isnumber", int> lua_isnumber_func;
static constexpr sdk::pdb_global_func<"lua_isstring", int> lua_isstring_func;
static constexpr sdk::pdb_global_func<"lua_iscfunction", int> lua_iscfunction_func;
static constexpr sdk::pdb_global_func<"lua_isuserdata", int> lua_isuserdata_func;
static constexpr sdk::pdb_global_func<"lua_type", int> lua_type_func;
static constexpr sdk::pdb_global_func<"lua_typename", const char *> lua_typename_func;

static constexpr sdk::pdb_global_func<"lua_tonumberx", lua_Number> lua_tonumberx_func;
static constexpr sdk::pdb_global_func<"lua_tointegerx", lua_Integer> lua_tointegerx_func;
static constexpr sdk::pdb_global_func<"lua_tounsignedx", lua_Unsigned> lua_tounsignedx_func;
static constexpr sdk::pdb_global_func<"lua_toboolean", int> lua_toboolean_func;
static constexpr sdk::pdb_global_func<"lua_tolstring", const char *> lua_tolstring_func;
static constexpr sdk::pdb_global_func<"lua_rawlen", size_t> lua_rawlen_func;
static constexpr sdk::pdb_global_func<"lua_tocfunction", lua_CFunction> lua_tocfunction_func;
static constexpr sdk::pdb_global_func<"lua_touserdata", void *> lua_touserdata_func;
static constexpr sdk::pdb_global_func<"lua_tothread", lua_State *> lua_tothread_func;
static constexpr sdk::pdb_global_func<"lua_topointer", void *> lua_topointer_func;

LUA_API int (lua_isnumber)(lua_State *L, int idx) {
    return lua_isnumber_func(true, L, idx);
}

LUA_API int (lua_isstring)(lua_State *L, int idx) {
    return lua_isstring_func(true, L, idx);
}

LUA_API int (lua_iscfunction)(lua_State *L, int idx) {
    return lua_iscfunction_func(true, L, idx);
}

LUA_API int (lua_isuserdata)(lua_State *L, int idx) {
    return lua_isuserdata_func(true, L, idx);
}

LUA_API int (lua_type)(lua_State *L, int idx) {
    return lua_type_func(true, L, idx);
}

LUA_API const char *(lua_typename)(lua_State *L, int tp) {
    return lua_typename_func(true, L, tp);
}

LUA_API lua_Number (lua_tonumberx)(lua_State *L, int idx, int *isnum) {
    return lua_tonumberx_func(true, L, idx, isnum);
}

LUA_API lua_Integer (lua_tointegerx)(lua_State *L, int idx, int *isnum) {
    return lua_tointegerx_func(true, L, idx, isnum);
}

LUA_API lua_Unsigned (lua_tounsignedx)(lua_State *L, int idx, int *isnum) {
    return lua_tounsignedx_func(true, L, idx, isnum);
}

LUA_API int (lua_toboolean)(lua_State *L, int idx) {
    return lua_toboolean_func(true, L, idx);
}

LUA_API const char *(lua_tolstring)(lua_State *L, int idx, size_t *len) {
    return lua_tolstring_func(true, L, idx, len);
}

LUA_API size_t (lua_rawlen)(lua_State *L, int idx) {
    return lua_rawlen_func(true, L, idx);
}

LUA_API lua_CFunction (lua_tocfunction)(lua_State *L, int idx) {
    return lua_tocfunction_func(true, L, idx);
}

LUA_API void *(lua_touserdata)(lua_State *L, int idx) {
    return lua_touserdata_func(true, L, idx);
}

LUA_API lua_State *(lua_tothread)(lua_State *L, int idx) {
    return lua_tothread_func(true, L, idx);
}

LUA_API const void *(lua_topointer)(lua_State *L, int idx) {
    return lua_topointer_func(true, L, idx);
}

/*
** Comparison and arithmetic functions
*/
static constexpr sdk::pdb_global_func<"lua_arith", void> lua_arith_func;
static constexpr sdk::pdb_global_func<"lua_rawequal", int> lua_rawequal_func;
static constexpr sdk::pdb_global_func<"lua_compare", int> lua_compare_func;

LUA_API void (lua_arith)(lua_State *L, int op) {
    return lua_arith_func(true, L, op);
}

LUA_API int (lua_rawequal)(lua_State *L, int idx1, int idx2) {
    return lua_rawequal_func(true, L, idx1, idx2);
}

LUA_API int (lua_compare)(lua_State *L, int idx1, int idx2, int op) {
    return lua_compare_func(true, L, idx1, idx2);
}

/*
** push functions (C -> stack)
*/
static constexpr sdk::pdb_global_func<"lua_pushnil", void> lua_pushnil_func;
static constexpr sdk::pdb_global_func<"lua_pushnumber", void> lua_pushnumber_func;
static constexpr sdk::pdb_global_func<"lua_pushinteger", void> lua_pushinteger_func;
static constexpr sdk::pdb_global_func<"lua_pushunsigned", void> lua_pushunsigned_func;
static constexpr sdk::pdb_global_func<"lua_pushlstring", const char *> lua_pushlstring_func;
static constexpr sdk::pdb_global_func<"lua_pushstring", const char *> lua_pushstring_func;
static constexpr sdk::pdb_global_func<"lua_pushvfstring", const char *> lua_pushvfstring_func;
static constexpr sdk::pdb_global_func<"lua_pushcclosure", void> lua_pushcclosure_func;
static constexpr sdk::pdb_global_func<"lua_pushboolean", void> lua_pushboolean_func;
static constexpr sdk::pdb_global_func<"lua_pushlightuserdata", void> lua_pushlightuserdata_func;
static constexpr sdk::pdb_global_func<"lua_pushthread", int> lua_pushthread_func;

LUA_API void (lua_pushnil)(lua_State *L) {
    return lua_pushnil_func(true, L);
}

LUA_API void (lua_pushnumber)(lua_State *L, lua_Number n) {
    return lua_pushnumber_func(true, L, n);
}

LUA_API void (lua_pushinteger)(lua_State *L, lua_Integer n) {
    return lua_pushinteger_func(true, L, n);
}

LUA_API void (lua_pushunsigned)(lua_State *L, lua_Unsigned n) {
    return lua_pushunsigned_func(true, L, n);
}

LUA_API const char *(lua_pushlstring)(lua_State *L, const char *s, size_t l) {
    return lua_pushlstring_func(true, L, s, l);
}

LUA_API const char *(lua_pushstring)(lua_State *L, const char *s) {
    return lua_pushstring_func(true, L, s);
}

LUA_API const char *(lua_pushvfstring)(lua_State *L, const char *fmt,
                                       va_list argp) {
    return lua_pushvfstring_func(true, L, fmt, argp);
}

LUA_API const char *(lua_pushfstring)(lua_State *L, const char *fmt, auto args...) {
    return lua_pushfstring_func(true, L, fmt, args);
}

LUA_API void (lua_pushcclosure)(lua_State *L, lua_CFunction fn, int n) {
    return lua_pushcclosure_func(true, L, fn, n);
}

LUA_API void (lua_pushboolean)(lua_State *L, int b) {
    return lua_pushboolean_func(true, L, b);
}

LUA_API void (lua_pushlightuserdata)(lua_State *L, void *p) {
    return lua_pushlightuserdata_func(true, L, p);
}

LUA_API int (lua_pushthread)(lua_State *L) {
    return lua_pushthread_func(true, L);
}

/*
** get functions (Lua -> stack)
*/
static constexpr sdk::pdb_global_func<"lua_getglobal", void> lua_getglobal_func;
static constexpr sdk::pdb_global_func<"lua_gettable", void> lua_gettable_func;
static constexpr sdk::pdb_global_func<"lua_getfield", void> lua_getfield_func;
static constexpr sdk::pdb_global_func<"lua_rawget", void> lua_rawget_func;
static constexpr sdk::pdb_global_func<"lua_rawgeti", void> lua_rawgeti_func;
static constexpr sdk::pdb_global_func<"lua_rawgetp", void> lua_rawgetp_func;
static constexpr sdk::pdb_global_func<"lua_createtable", void> lua_createtable_func;
static constexpr sdk::pdb_global_func<"lua_newuserdata", void *> lua_newuserdata_func;
static constexpr sdk::pdb_global_func<"lua_getmetatable", int> lua_getmetatable_func;
static constexpr sdk::pdb_global_func<"lua_getuservalue", void> lua_getuservalue_func;


LUA_API void (lua_getglobal)(lua_State *L, const char *var) {
    return lua_getglobal_func(true, L, var);
}

LUA_API void (lua_gettable)(lua_State *L, int idx) {
    return lua_gettable_func(true, L, idx);
}

LUA_API void (lua_getfield)(lua_State *L, int idx, const char *k) {
    return lua_getfield_func(true, L, idx, k);
}

LUA_API void (lua_rawget)(lua_State *L, int idx) {
    return lua_rawget_func(true, L, idx);
}

LUA_API void (lua_rawgeti)(lua_State *L, int idx, int n) {
    return lua_rawgeti_func(true, L, idx, n);
}

LUA_API void (lua_rawgetp)(lua_State *L, int idx, const void *p) {
    return lua_rawgetp_func(true, L, idx, p);
}

LUA_API void (lua_createtable)(lua_State *L, int narr, int nrec) {
    return lua_createtable_func(true, L, narr, nrec);
}

LUA_API void *(lua_newuserdata)(lua_State *L, size_t sz) {
    return lua_newuserdata_func(true, L, sz);
}

LUA_API int (lua_getmetatable)(lua_State *L, int objindex) {
    return lua_getmetatable_func(L, objindex);
}

LUA_API void (lua_getuservalue)(lua_State *L, int idx) {
    return lua_getuservalue_func(L, idx);
}

/*
** set functions (stack -> Lua)
*/
static constexpr sdk::pdb_global_func<"lua_setglobal", void> lua_setglobal_func;
static constexpr sdk::pdb_global_func<"lua_settable", void> lua_settable_func;
static constexpr sdk::pdb_global_func<"lua_setfield", void> lua_setfield_func;
static constexpr sdk::pdb_global_func<"lua_rawset", void> lua_rawset_func;
static constexpr sdk::pdb_global_func<"lua_rawseti", void> lua_rawseti_func;
static constexpr sdk::pdb_global_func<"lua_rawsetp", void> lua_rawsetp_func;
static constexpr sdk::pdb_global_func<"lua_setmetatable", int> lua_setmetatable_func;
static constexpr sdk::pdb_global_func<"lua_setuservalue", void> lua_setuservalue_func;

LUA_API void (lua_setglobal)(lua_State *L, const char *var) {
    return lua_setglobal_func(true, L, var);
}

LUA_API void (lua_settable)(lua_State *L, int idx) {
    return lua_settable_func(true, L, idx);
}

LUA_API void (lua_setfield)(lua_State *L, int idx, const char *k) {
    return lua_setfield_func(true, L, idx, k);
}

LUA_API void (lua_rawset)(lua_State *L, int idx) {
    return lua_rawset_func(true, L, idx);
}

LUA_API void (lua_rawseti)(lua_State *L, int idx, int n) {
    return lua_rawseti_func(true, L, idx, n);
}

LUA_API void (lua_rawsetp)(lua_State *L, int idx, const void *p) {
    return lua_rawsetp_func(true, L, idx, p);
}

LUA_API int (lua_setmetatable)(lua_State *L, int objindex) {
    return lua_setmetatable_func(true, L, objindex);
}

LUA_API void (lua_setuservalue)(lua_State *L, int idx) {
    return lua_setuservalue_func(true, L, idx);
}

/*
** 'load' and 'call' functions (load and run Lua code)
*/
static constexpr sdk::pdb_global_func<"lua_callk", void> lua_callk_func;
static constexpr sdk::pdb_global_func<"lua_getctx", int> lua_getctx_func;
static constexpr sdk::pdb_global_func<"lua_pcallk", int> lua_pcallk_func;
static constexpr sdk::pdb_global_func<"lua_load", int> lua_load_func;
static constexpr sdk::pdb_global_func<"lua_dump", int> lua_dump_func;

LUA_API void (lua_callk)(lua_State *L, int nargs, int nresults, int ctx,
                         lua_CFunction k) {
    return lua_callk_func(true, L, nargs, nresults, ctx, k);
}

LUA_API int (lua_getctx)(lua_State *L, int *ctx) {
    return lua_getctx_func(true, L, ctx);
}

LUA_API int (lua_pcallk)(lua_State *L, int nargs, int nresults, int errfunc,
                         int ctx, lua_CFunction k) {
    return lua_pcallk_func(true, L, nargs, nresults, ctx, k);
}

LUA_API int (lua_load)(lua_State *L, lua_Reader reader, void *dt,
                       const char *chunkname,
                       const char *mode) {
    return lua_load_func(true, L, reader, dt, chunkname, mode);
}

LUA_API int (lua_dump)(lua_State *L, lua_Writer writer, void *data) {
    return lua_dump_func(true, L, writer, data);
}

/*
** coroutine functions
*/
static constexpr sdk::pdb_global_func<"lua_yieldk", int> lua_yieldk_func;
static constexpr sdk::pdb_global_func<"lua_resume", int> lua_resume_func;
static constexpr sdk::pdb_global_func<"lua_status", int> lua_status_func;

LUA_API int (lua_yieldk)(lua_State *L, int nresults, int ctx,
                         lua_CFunction k) {
    return lua_yieldk_func(true, L, nresults, ctx, k);
}

LUA_API int (lua_resume)(lua_State *L, lua_State *from, int narg) {
    return lua_resume_func(true, L, from, narg);
}

LUA_API int (lua_status)(lua_State *L) {
    return lua_status_func(true, L);
}

/*
** garbage-collection function and options
*/
static constexpr sdk::pdb_global_func<"lua_gc", int> lua_gc_func;

LUA_API int (lua_gc)(lua_State *L, int what, int data) {
    return lua_gc_func(true, L, what, data);
}

/*
** miscellaneous functions
*/
static constexpr sdk::pdb_global_func<"lua_error", int> lua_error_func;
static constexpr sdk::pdb_global_func<"lua_next", int> lua_next_func;
static constexpr sdk::pdb_global_func<"lua_concat", void> lua_concat_func;
static constexpr sdk::pdb_global_func<"lua_len", void> lua_len_func;
static constexpr sdk::pdb_global_func<"lua_getallocf", lua_Alloc> lua_getallocf_func;
static constexpr sdk::pdb_global_func<"lua_setallocf", void> lua_setallocf_func;

LUA_API int (lua_error)(lua_State *L) {
    return lua_error_func(true, L);
}

LUA_API int (lua_next)(lua_State *L, int idx) {
    return lua_next_func(true, L, idx);
}

LUA_API void (lua_concat)(lua_State *L, int n) {
    return lua_concat_func(true, L, n);
}

LUA_API void (lua_len)(lua_State *L, int idx) {
    return lua_len_func(true, L, idx);
}

LUA_API lua_Alloc (lua_getallocf)(lua_State *L, void **ud) {
    return lua_getallocf_func(true, L, ud);
}

LUA_API void (lua_setallocf)(lua_State *L, lua_Alloc f, void *ud) {
    return lua_setallocf_func(true, L, f, ud);
}

/*
** {======================================================================
** Debug API
** =======================================================================
*/
static constexpr sdk::pdb_global_func<"lua_getstack", int> lua_getstack_func;
static constexpr sdk::pdb_global_func<"lua_getinfo", int> lua_getinfo_func;
static constexpr sdk::pdb_global_func<"lua_getlocal", const char *> lua_getlocal_func;
static constexpr sdk::pdb_global_func<"lua_setlocal", const char *> lua_setlocal_func;
static constexpr sdk::pdb_global_func<"lua_getupvalue", const char *> lua_getupvalue_func;
static constexpr sdk::pdb_global_func<"lua_setupvalue", const char *> lua_setupvalue_func;
static constexpr sdk::pdb_global_func<"lua_upvalueid", void *> lua_upvalueid_func;
static constexpr sdk::pdb_global_func<"lua_upvaluejoin", void> lua_upvaluejoin_func;
static constexpr sdk::pdb_global_func<"lua_sethook", int> lua_sethook_func;
static constexpr sdk::pdb_global_func<"lua_gethook", lua_Hook> lua_gethook_func;
static constexpr sdk::pdb_global_func<"lua_gethookmask", int> lua_gethookmask_func;
static constexpr sdk::pdb_global_func<"lua_gethookcount", int> lua_gethookcount_func;

LUA_API int (lua_getstack)(lua_State *L, int level, lua_Debug *ar) {
    return lua_getstack_func(true, L, ar);
}

LUA_API int (lua_getinfo)(lua_State *L, const char *what, lua_Debug *ar) {
    return lua_getinfo_func(true, L, what, ar);
}

LUA_API const char *(lua_getlocal)(lua_State *L, const lua_Debug *ar, int n) {
    return lua_getlocal_func(true, L, ar, n);
}

LUA_API const char *(lua_setlocal)(lua_State *L, const lua_Debug *ar, int n) {
    return lua_setlocal_func(true, L, ar, n);
}

LUA_API const char *(lua_getupvalue)(lua_State *L, int funcindex, int n) {
    return lua_getupvalue_func(true, L, funcindex, n);
}

LUA_API const char *(lua_setupvalue)(lua_State *L, int funcindex, int n) {
    return lua_setupvalue_func(true, L, funcindex, n);
}

LUA_API void *(lua_upvalueid)(lua_State *L, int fidx, int n) {
    return lua_upvalueid_func(true, L, fidx, n);
}

LUA_API void (lua_upvaluejoin)(lua_State *L, int fidx1, int n1,
                               int fidx2, int n2) {
    return lua_upvaluejoin_func(true, L, fidx1, n1, fidx2, n2);
}

LUA_API int (lua_sethook)(lua_State *L, lua_Hook func, int mask, int count) {
    return lua_sethook_func(true, L, func, mask, count);
}

LUA_API lua_Hook (lua_gethook)(lua_State *L) {
    return lua_gethook_func(true, L);
}

LUA_API int (lua_gethookmask)(lua_State *L) {
    return lua_gethookmask_func(true, L);
}

LUA_API int (lua_gethookcount)(lua_State *L) {
    return lua_gethookcount_func(true, L);
}

static const sdk::pdb_sym_tree Lua_tree{
    &lua_absindex_func,
    &lua_gettop_func,
    &lua_settop_func,
    &lua_pushvalue_func,
    &lua_remove_func,
    &lua_insert_func,
    &lua_replace_func,
    &lua_copy_func,
    &lua_checkstack_func,
    &lua_xmove_func,
    &lua_isnumber_func,
    &lua_isstring_func,
    &lua_iscfunction_func,
    &lua_isuserdata_func,
    &lua_type_func,
    &lua_typename_func,
    &lua_tonumberx_func,
    &lua_tointegerx_func,
    &lua_tounsignedx_func,
    &lua_toboolean_func,
    &lua_tolstring_func,
    &lua_rawlen_func,
    &lua_tocfunction_func,
    &lua_touserdata_func,
    &lua_tothread_func,
    &lua_topointer_func,
    &lua_arith_func,
    &lua_rawequal_func,
    &lua_compare_func,
    &lua_pushnil_func,
    &lua_pushnumber_func,
    &lua_pushinteger_func,
    &lua_pushunsigned_func,
    &lua_pushlstring_func,
    &lua_pushstring_func,
    &lua_pushvfstring_func,
    &lua_pushcclosure_func,
    &lua_pushboolean_func,
    &lua_pushlightuserdata_func,
    &lua_pushthread_func,
    &lua_getglobal_func,
    &lua_gettable_func,
    &lua_getfield_func,
    &lua_rawget_func,
    &lua_rawgeti_func,
    &lua_rawgetp_func,
    &lua_createtable_func,
    &lua_newuserdata_func,
    &lua_getmetatable_func,
    &lua_getuservalue_func,
    &lua_setglobal_func,
    &lua_settable_func,
    &lua_setfield_func,
    &lua_rawset_func,
    &lua_rawseti_func,
    &lua_rawsetp_func,
    &lua_setmetatable_func,
    &lua_setuservalue_func,
    &lua_callk_func,
    &lua_getctx_func,
    &lua_pcallk_func,
    &lua_load_func,
    &lua_dump_func,
    &lua_yieldk_func,
    &lua_resume_func,
    &lua_status_func,
    &lua_gc_func,
    &lua_error_func,
    &lua_next_func,
    &lua_concat_func,
    &lua_len_func,
    &lua_getallocf_func,
    &lua_setallocf_func,
    &lua_getstack_func,
    &lua_getinfo_func,
    &lua_getlocal_func,
    &lua_setlocal_func,
    &lua_getupvalue_func,
    &lua_setupvalue_func,
    &lua_upvalueid_func,
    &lua_upvaluejoin_func,
    &lua_sethook_func,
    &lua_gethook_func,
    &lua_gethookmask_func,
    &lua_gethookcount_func,
};

/**
 * LuaX
 */
static constexpr sdk::pdb_global_func<"luaL_getmetafield", int> luaL_getmetafield_func;
static constexpr sdk::pdb_global_func<"luaL_callmeta", int> luaL_callmeta_func;
static constexpr sdk::pdb_global_func<"luaL_tolstring", const char *> luaL_tolstring_func;
static constexpr sdk::pdb_global_func<"luaL_argerror", int> luaL_argerror_func;
static constexpr sdk::pdb_global_func<"luaL_checklstring", const char *> luaL_checklstring_func;
static constexpr sdk::pdb_global_func<"luaL_optlstring", const char *> luaL_optlstring_func;
static constexpr sdk::pdb_global_func<"luaL_checknumber", lua_Number> luaL_checknumber_func;
static constexpr sdk::pdb_global_func<"luaL_optnumber", lua_Number> luaL_optnumber_func;
static constexpr sdk::pdb_global_func<"luaL_checkinteger", lua_Integer> luaL_checkinteger_func;
static constexpr sdk::pdb_global_func<"luaL_optinteger", lua_Integer> luaL_optinteger_func;
static constexpr sdk::pdb_global_func<"luaL_checkunsigned", lua_Unsigned> luaL_checkunsigned_func;
static constexpr sdk::pdb_global_func<"luaL_optunsigned", lua_Unsigned> luaL_optunsigned_func;
static constexpr sdk::pdb_global_func<"luaL_checkstack", void> luaL_checkstack_func;
static constexpr sdk::pdb_global_func<"luaL_checktype", void> luaL_checktype_func;
static constexpr sdk::pdb_global_func<"luaL_checkany", void> luaL_checkany_func;
static constexpr sdk::pdb_global_func<"luaL_newmetatable", int> luaL_newmetatable_func;
static constexpr sdk::pdb_global_func<"luaL_setmetatable", void> luaL_setmetatable_func;
static constexpr sdk::pdb_global_func<"luaL_testudata", void *> luaL_testudata_func;
static constexpr sdk::pdb_global_func<"luaL_checkudata", void *> luaL_checkudata_func;
static constexpr sdk::pdb_global_func<"luaL_where", void> luaL_where_func;
static constexpr sdk::pdb_global_func<"luaL_error", int> luaL_error_func;
static constexpr sdk::pdb_global_func<"luaL_checkoption", int> luaL_checkoption_func;
static constexpr sdk::pdb_global_func<"luaL_fileresult", int> luaL_fileresult_func;
static constexpr sdk::pdb_global_func<"luaL_execresult", int> luaL_execresult_func;
static constexpr sdk::pdb_global_func<"luaL_ref", int> luaL_ref_func;
static constexpr sdk::pdb_global_func<"luaL_unref", void> luaL_unref_func;
static constexpr sdk::pdb_global_func<"luaL_loadfilex", int> luaL_loadfilex_func;
static constexpr sdk::pdb_global_func<"luaL_loadbufferx", int> luaL_loadbufferx_func;
static constexpr sdk::pdb_global_func<"luaL_loadstring", int> luaL_loadstring_func;
static constexpr sdk::pdb_global_func<"luaL_newstate", lua_State *> luaL_newstate_func;
static constexpr sdk::pdb_global_func<"luaL_len", int> luaL_len_func;
static constexpr sdk::pdb_global_func<"luaL_gsub", const char *> luaL_gsub_func;
static constexpr sdk::pdb_global_func<"luaL_setfuncs", void> luaL_setfuncs_func;
static constexpr sdk::pdb_global_func<"luaL_getsubtable", int> luaL_getsubtable_func;
static constexpr sdk::pdb_global_func<"luaL_traceback", void> luaL_traceback_func;
static constexpr sdk::pdb_global_func<"luaL_requiref", void> luaL_requiref_func;
static constexpr sdk::pdb_global_func<"luaL_buffinit", void> luaL_buffinit_func;
static constexpr sdk::pdb_global_func<"luaL_prepbuffsize", char *> luaL_prepbuffsize_func;
static constexpr sdk::pdb_global_func<"luaL_addlstring", void> luaL_addlstring_func;
static constexpr sdk::pdb_global_func<"luaL_addstring", void> luaL_addstring_func;
static constexpr sdk::pdb_global_func<"luaL_addvalue", void> luaL_addvalue_func;
static constexpr sdk::pdb_global_func<"luaL_pushresult", void> luaL_pushresult_func;
static constexpr sdk::pdb_global_func<"luaL_pushresultsize", void> luaL_pushresultsize_func;
static constexpr sdk::pdb_global_func<"luaL_buffinitsize", char *> luaL_buffinitsize_func;


LUALIB_API int (luaL_getmetafield)(lua_State *L, int obj, const char *e) {
    return luaL_getmetafield_func(true, L, obj, e);
}

LUALIB_API int (luaL_callmeta)(lua_State *L, int obj, const char *e) {
    return luaL_callmeta_func(true, L, obj, e);
}

LUALIB_API const char *(luaL_tolstring)(lua_State *L, int idx, size_t *len) {
    return luaL_tolstring_func(true, L, idx, len);
}

LUALIB_API int (luaL_argerror)(lua_State *L, int numarg, const char *extramsg) {
    return luaL_argerror_func(true, L, numarg, extramsg);
}

LUALIB_API const char *(luaL_checklstring)(lua_State *L, int numArg, size_t *l) {
    return luaL_checklstring_func(true, L, numArg, l);
}

LUALIB_API const char *(luaL_optlstring)(lua_State *L, int numArg, const char *def, size_t *l) {
    return luaL_optlstring_func(L, numArg, def, l);
}

LUALIB_API lua_Number (luaL_checknumber)(lua_State *L, int numArg) {
    return luaL_checknumber_func(true, L, numArg);
}

LUALIB_API lua_Number (luaL_optnumber)(lua_State *L, int nArg, lua_Number def) {
    return luaL_optnumber_func(true, L, nArg, def);
}

LUALIB_API lua_Integer (luaL_checkinteger)(lua_State *L, int numArg) {
    return luaL_checkinteger_func(true, L, numArg);
}

LUALIB_API lua_Integer (luaL_optinteger)(lua_State *L, int nArg, lua_Integer def) {
    return luaL_optinteger_func(true, L, nArg, def);
}

LUALIB_API lua_Unsigned (luaL_checkunsigned)(lua_State *L, int numArg) {
    return luaL_checkunsigned_func(true, L, numArg);
}

LUALIB_API lua_Unsigned (luaL_optunsigned)(lua_State *L, int numArg, lua_Unsigned def) {
    return luaL_optunsigned_func(true, L, numArg, def);
}

LUALIB_API void (luaL_checkstack)(lua_State *L, int sz, const char *msg) {
    luaL_checkstack_func(true, L, sz, msg);
}

LUALIB_API void (luaL_checktype)(lua_State *L, int narg, int t) {
    luaL_checktype_func(true, L, narg, t);
}

LUALIB_API void (luaL_checkany)(lua_State *L, int narg) {
    luaL_checkany_func(true, L, narg);
}

LUALIB_API int (luaL_newmetatable)(lua_State *L, const char *tname) {
    return luaL_newmetatable_func(true, L, tname);
}

LUALIB_API void (luaL_setmetatable)(lua_State *L, const char *tname) {
    luaL_setmetatable_func(true, L, tname);
}

LUALIB_API void *(luaL_testudata)(lua_State *L, int ud, const char *tname) {
    return luaL_testudata_func(true, L, ud, tname);
}

LUALIB_API void *(luaL_checkudata)(lua_State *L, int ud, const char *tname) {
    return luaL_checkudata_func(true, L, ud, tname);
}

LUALIB_API void (luaL_where)(lua_State *L, int lvl) {
    luaL_where_func(true, L, lvl);
}

LUALIB_API int (luaL_error)(lua_State *L, const char *fmt, ...) {
    return luaL_error_func(true, L, fmt);
}

LUALIB_API int (luaL_checkoption)(lua_State *L, int narg, const char *def, const char *const lst[]) {
    return luaL_checkoption_func(true, L, narg, def, lst);
}

LUALIB_API int (luaL_fileresult)(lua_State *L, int stat, const char *fname) {
    return luaL_fileresult_func(true, L, stat, fname);
}

LUALIB_API int (luaL_execresult)(lua_State *L, int stat) {
    return luaL_execresult_func(true, L, stat);
}

LUALIB_API int (luaL_ref)(lua_State *L, int t) {
    return luaL_ref_func(true, L, t);
}

LUALIB_API void (luaL_unref)(lua_State *L, int t, int ref) {
    luaL_unref_func(true, L, t, ref);
}

LUALIB_API int (luaL_loadfilex)(lua_State *L, const char *filename, const char *mode) {
    return luaL_loadfilex_func(true, L, filename, mode);
}

LUALIB_API int (luaL_loadbufferx)(lua_State *L, const char *buff, size_t sz, const char *name, const char *mode) {
    return luaL_loadbufferx_func(true, L, buff, sz, name, mode);
}

LUALIB_API int (luaL_loadstring)(lua_State *L, const char *s) {
    return luaL_loadstring_func(true, L, s);
}

LUALIB_API lua_State *(luaL_newstate)() {
    return luaL_newstate_func(true);
}

LUALIB_API int (luaL_len)(lua_State *L, int idx) {
    return luaL_len_func(true, L, idx);
}

LUALIB_API const char *(luaL_gsub)(lua_State *L, const char *s, const char *p, const char *r) {
    return luaL_gsub_func(true, L, s, p, r);
}

LUALIB_API void (luaL_setfuncs)(lua_State *L, const luaL_Reg *l, int nup) {
    luaL_setfuncs_func(true, L, l, nup);
}

LUALIB_API int (luaL_getsubtable)(lua_State *L, int idx, const char *fname) {
    return luaL_getsubtable_func(true, L, idx, fname);
}

LUALIB_API void (luaL_traceback)(lua_State *L, lua_State *L1, const char *msg, int level) {
    luaL_traceback_func(true, L, L1, msg, level);
}

LUALIB_API void (luaL_requiref)(lua_State *L, const char *modname, lua_CFunction openf, int glb) {
    luaL_requiref_func(true, L, modname, openf, glb);
}

LUALIB_API void (luaL_buffinit)(lua_State *L, luaL_Buffer *B) {
    luaL_buffinit_func(true, L, B);
}

LUALIB_API char *(luaL_prepbuffsize)(luaL_Buffer *B, size_t sz) {
    return luaL_prepbuffsize_func(true, B, sz);
}

LUALIB_API void (luaL_addlstring)(luaL_Buffer *B, const char *s, size_t l) {
    luaL_addlstring_func(true, B, s, l);
}

LUALIB_API void (luaL_addstring)(luaL_Buffer *B, const char *s) {
    luaL_addstring_func(true, B, s);
}

LUALIB_API void (luaL_addvalue)(luaL_Buffer *B) {
    luaL_addvalue_func(true, B);
}

LUALIB_API void (luaL_pushresult)(luaL_Buffer *B) {
    luaL_pushresult_func(true, B);
}

LUALIB_API void (luaL_pushresultsize)(luaL_Buffer *B, size_t sz) {
    luaL_pushresultsize_func(true, B, sz);
}

LUALIB_API char *(luaL_buffinitsize)(lua_State *L, luaL_Buffer *B, size_t sz) {
    return luaL_buffinitsize_func(true, L, B, sz);
}

static const sdk::pdb_sym_tree LuaX_tree{
    &luaL_getmetafield_func,
    &luaL_callmeta_func,
    &luaL_tolstring_func,
    &luaL_argerror_func,
    &luaL_checklstring_func,
    &luaL_optlstring_func,
    &luaL_checknumber_func,
    &luaL_optnumber_func,
    &luaL_checkinteger_func,
    &luaL_optinteger_func,
    &luaL_checkunsigned_func,
    &luaL_optunsigned_func,
    &luaL_checkstack_func,
    &luaL_checktype_func,
    &luaL_checkany_func,
    &luaL_newmetatable_func,
    &luaL_setmetatable_func,
    &luaL_testudata_func,
    &luaL_checkudata_func,
    &luaL_where_func,
    &luaL_error_func,
    &luaL_checkoption_func,
    &luaL_fileresult_func,
    &luaL_execresult_func,
    &luaL_ref_func,
    &luaL_unref_func,
    &luaL_loadfilex_func,
    &luaL_loadbufferx_func,
    &luaL_loadstring_func,
    &luaL_newstate_func,
    &luaL_len_func,
    &luaL_gsub_func,
    &luaL_setfuncs_func,
    &luaL_getsubtable_func,
    &luaL_traceback_func,
    &luaL_requiref_func,
    &luaL_buffinit_func,
    &luaL_prepbuffsize_func,
    &luaL_addlstring_func,
    &luaL_addstring_func,
    &luaL_addvalue_func,
    &luaL_pushresult_func,
    &luaL_pushresultsize_func,
    &luaL_buffinitsize_func
};

#endif
