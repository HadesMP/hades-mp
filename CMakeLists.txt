cmake_minimum_required(VERSION 3.25)
project(hades_mp)

set(CMAKE_CXX_STANDARD 20)

include_directories(sdk/include)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(sdk)
add_subdirectory(loader)
add_subdirectory(network)
add_subdirectory(server)
add_subdirectory(hades-i)
add_subdirectory(hades-ii)