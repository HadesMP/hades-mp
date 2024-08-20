cmake_minimum_required(VERSION 3.25)

link_directories(lib)
include_directories(include)

set(LUA_INCLUDES
        include/lua/lua.h
        include/lua/defs.hpp
        include/lua/luaconf.h
        include/lua/lauxlib.h)

set(ENGINE_INCLUDES
        include/sgg/App.hpp
        include/sgg/GUI/GameScreen.hpp
        include/sgg/Platform/FileSystem.hpp
        include/sgg/Script/ScriptManager.hpp
        include/sgg/Platform/PlatformFile.hpp)

set(SDK_INCLUDES
        include/sdk/sdk.hpp
        include/sdk/engine.hpp
        include/sdk/logger.hpp
        include/sdk/sym/defs.hpp
        include/sdk/sym/resolve.hpp)

set(SDK_SOURCES
        src/sdk.cpp
        src/sym_resolve.cpp)

add_library(sdk STATIC ${LUA_INCLUDES} ${ENGINE_INCLUDES} ${SDK_INCLUDES} ${SDK_SOURCES})