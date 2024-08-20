# Hades - Multiplayer Mod & Loader

## State of Project
The project is currently heavily work in progress, the base required to interface with Lua & the SuperGiant Games engine is complete, although the networking code & script changes to make the game(s) multiplayer therein is not.

## Architecture
The project aims to have as little platform dependency as possible, meaning, ideally it will only modify the handling of loading script/resource files when mods require it.
A network interface will be exposed through lua, leaving most of the (multiplayer) mod in the script space.

## Contribution
Currently, I am seeking help in laying a solid foundation for the netcode, for both versions of the game (they will obviously differ slightly, but most of it should be kept in sync).

## Table of Contents
1. `hades-i` - Hades I specific (networking, script & sdk) code
2. `hades-ii` - Hades II specific (networking, script & sdk) code
3. `network` - Base networking code, including ASIO
4. `sdk` - Debug symbol resolution & misc utility code
5. `loader` - Version library proxy (loaded by `crashpad_handler.exe` in Hades II)
6. `server` - Server (including local host) code
