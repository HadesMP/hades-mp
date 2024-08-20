#ifndef ENGINE_GAMESCREEN_HPP
#define ENGINE_GAMESCREEN_HPP

#include "sdk/sym/defs.hpp"

namespace sgg {
    static constexpr sdk::pdb_struct<struct GameScreen, "sgg::GameScreen"> GameScreen_struct;
    static constexpr sdk::pdb_struct<struct GameScreenVTable, "sgg::GameScreen::VTable"> GameScreenVTable_struct;

    enum ScreenType : uint32_t {
        Game = 0x1,
        Menu = 0x3,
        Ingameui = 0x7,
        Shell = 0xb,
        About = 0x1b,
        Announcement = 0x2b,
        DebugKey = 0x43,
        ExitDialog = 0x83,
        Gameplay = 0x101,
        GameStart = 0x203,
        Settings = 0x40b,
        KeyMapping = 0xc0b,
        Language = 0x100b,
        Launch = 0x2003,
        Load = 0x4003,
        LoadMap = 0x8003,
        LoadSave = 0x10003,
        MainMenu = 0x20003,
        MessageDialog = 0x40003,
        PatchNotes = 0x8000b,
        Pause = 0x100003,
        Profile = 0x20000b,
        Resolution = 0x40000b,
        MiscSettings = 0x80040b,
        SettingsMenu = 0x100000b,
        StartNew = 0x200000b,
        CloudSettingsMenu = 0x400000b
    };

    struct GameScreen {
        struct {
            void (*OnExit)(GameScreen *);
            void (*LoadContent)(GameScreen *);
            void (*UnloadContent)(GameScreen *);
            void (*Update)(GameScreen *, float elapsedSeconds, void * inputHandlers);
            void (*HandleInput)(GameScreen *, struct InputHandler * handler, float elapsedSeconds);
            void (*HandleNoInput)(GameScreen *);
            void (*Draw)(GameScreen *, float elapsedSeconds);
            void (*ExitScreen)(GameScreen *);
            void (*Clear)(GameScreen *);
            void (*Init)(GameScreen *, struct ScreenManager * manager, void *);
            uint32_t(*GetType)(GameScreen *);
        } *VTable;
    };
}

#endif //ENGINE_GAMESCREEN_HPP
