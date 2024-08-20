enable_language(ASM_MASM)

include_directories(include)

set(LOADER_SOURCES
        def/library.asm
        def/library.def
        src/DllMain.cpp)

add_library(loader SHARED ${LOADER_SOURCES})
target_link_libraries(loader sdk)
target_link_directories(loader PRIVATE ../sdk/lib)
set_target_properties(loader PROPERTIES OUTPUT_NAME "version")