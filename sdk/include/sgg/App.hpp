#ifndef ENGINE_APP_HPP
#define ENGINE_APP_HPP

#include "sdk/sym/defs.hpp"

namespace sgg {
    static constexpr sdk::pdb_global_func<"AppMain", int> AppMain_func;
    static constexpr sdk::pdb_struct<struct App, "sgg__App"> App_struct;
    static constexpr sdk::pdb_struct_func<App_struct, "?Draw@App@sgg@@AEAAXM@Z", void> App_Draw;
    static constexpr sdk::pdb_struct_func<App_struct, "?Update@App@sgg@@AEAAXM@Z", void> App_Update;
    static constexpr sdk::pdb_struct_func<App_struct, "?UpdateAndDraw@App@sgg@@QEAAXM@Z", void> App_UpdateAndDraw;
    static sdk::pdb_sym_tree App_tree {
        &App_struct,
        &AppMain_func,
        &App_Draw,
        &App_Update,
        &App_UpdateAndDraw,
    };

    struct App : sdk::struct_wrapper<App_struct> {
        void Draw(float elapsedSeconds) {
            return App_Draw(true, this, elapsedSeconds);
        }

        void Update(float elapsedSeconds) {
            return App_Update(true, this, elapsedSeconds);
        }

        void UpdateAndDraw(float elapsedSeconds) {
            return App_UpdateAndDraw(true, this, elapsedSeconds);
        }
    };
} // namespace sgg

#endif //ENGINE_APP_HPP
