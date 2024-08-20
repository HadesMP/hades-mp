#ifndef SDK_ENGINE_HPP
#define SDK_ENGINE_HPP

#include "lua/defs.hpp"
#include "sgg/App.hpp"
#include "sgg/Platform/FileSystem.hpp"
#include "sgg/Script/ScriptManager.hpp"

namespace sdk {
    void add_engine_trees_to_resolver() {
        Lua_tree.add_to_resolver();
        LuaX_tree.add_to_resolver();
        sgg::App_tree.add_to_resolver();
        sgg::FileSystem_tree.add_to_resolver();
        sgg::ScriptManager_tree.add_to_resolver();
    }
}

#endif //SDK_ENGINE_HPP
