set(PACKET_API
        include/network/packet/packet.hpp
        include/network/packet/packet_buffer.hpp
        include/network/packet/packet_encoder.hpp
        include/network/packet/packet_decoder.hpp
        include/network/packet/packet_registry.hpp)

set(INTERFACE_API
    include/network/network_client.hpp
    include/network/network_server.hpp)

set(PROTOCOL_API
        include/network/protocol/packets.hpp
        include/network/protocol/protocol.hpp)

set(NETWORK_SOURCES ${PACKET_API} ${INTERFACE_API} ${PROTOCOL_API})

add_library(network STATIC ${NETWORK_SOURCES})
set_target_properties(network PROPERTIES LINKER_LANGUAGE CXX)