set(HADES_II_SOURCES
        src/DllMain.cpp
        src/mod/main_menu.cpp
        include/mod/main_menu.hpp
        src/net/network_manager.cpp)

include_directories(include)

add_library(hades-ii SHARED ${HADES_II_SOURCES})
target_link_libraries(hades-ii sdk)
target_link_directories(hades-ii PRIVATE ../sdk/lib)
set_target_properties(hades-ii PROPERTIES OUTPUT_NAME "hades-mp")

set(HADES_II_PATH
        "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Hades II")

if (EXISTS "${HADES_II_PATH}")
    add_custom_command(
            TARGET hades-ii POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hades-ii> ${HADES_II_PATH}\\Ship
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:loader> ${HADES_II_PATH}\\Ship
            COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}\\content ${HADES_II_PATH}\\Multiplayer)
else ()
    message(WARNING "Hades II installation path (${HADES_II_PATH}) does not exist. Please change it in CMakeLists.txt")
endif ()