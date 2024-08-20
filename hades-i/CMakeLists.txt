set(HADES_I_SOURCES
        src/DllMain.cpp)

add_library(hades-i SHARED ${HADES_I_SOURCES})
target_link_libraries(hades-i sdk)
target_link_directories(hades-i PRIVATE ../sdk/lib)
set_target_properties(hades-i PROPERTIES OUTPUT_NAME "hades-mp")

set(HADES_I_PATH
        "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Hades\\x64")

if (EXISTS "${HADES_I_PATH}")
    add_custom_command(
            TARGET hades-i POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hades-i> ${HADES_I_PATH}
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:loader> ${HADES_I_PATH})
else ()
    message(WARNING "Hades I installation path (${HADES_I_PATH}) does not exist. Please change it in CMakeLists.txt")
endif ()