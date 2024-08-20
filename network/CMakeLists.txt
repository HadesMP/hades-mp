set(NETWORK_SOURCES
        include/net/messages.hpp src/messages.cpp)

include_directories(include)

add_library(network STATIC ${NETWORK_SOURCES})