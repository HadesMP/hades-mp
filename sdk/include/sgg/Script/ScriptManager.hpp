//
// Created by Decencies on 19/05/2024.
//

#ifndef HADES_MP_SCRIPTMANAGER_HPP
#define HADES_MP_SCRIPTMANAGER_HPP

#include "sdk/sym/defs.hpp"

namespace sgg {
    static constexpr sdk::pdb_struct<struct ScriptManager, "sgg::ScriptManager"> ScriptManager_struct;
    static constexpr sdk::pdb_struct_func<ScriptManager_struct, "Load", bool> ScriptManager_Load;
    static const sdk::pdb_sym_tree ScriptManager_tree {
            &ScriptManager_struct,
            &ScriptManager_Load
    };

    struct ScriptManager {
        static bool Load(const char *scriptFile) {
            return ScriptManager_Load(true, scriptFile);
        }
    };
}

#endif //HADES_MP_SCRIPTMANAGER_HPP
