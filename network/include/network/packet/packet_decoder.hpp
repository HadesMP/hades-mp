#ifndef NETWORK_PACKETDECODER_HPP
#define NETWORK_PACKETDECODER_HPP

#include <network/packet/packet.hpp>
#include <network/packet/packet_buffer.hpp>
#include <network/protocol/protocol.hpp>

namespace network {
    class packet_decoder {
    public:
        packet_decoder() = delete;

        static std::unique_ptr<packet> decode_packet(packet_buffer &buffer) {
            const int id = buffer.read_var_int();
            const auto protocol = protocol::instance();
            const auto registry = protocol.registry();
            const auto protocol_state = protocol.state();
            auto packet = registry.construct_packet(protocol_state, id);
            if (!packet) {
                throw std::runtime_error("packet not found (wrong state?)");
            }

            packet->read(buffer);
            return packet;
        }
    };
}


#endif // NETWORK_PACKETDECODER_HPP
