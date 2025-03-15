#ifndef NETWORK_PACKETENCODER_HPP
#define NETWORK_PACKETENCODER_HPP

#include <network/packet/packet.hpp>
#include <network/packet/packet_buffer.hpp>
#include <network/protocol/protocol.hpp>

namespace network {
    class packet_encoder {
    public:
        packet_encoder() = delete;

        static packet_buffer encode_packet(const packet &packet) {
            if (packet.state() != protocol::instance().state()) {
                throw std::invalid_argument("packet is not in state");
            }
            packet_buffer buffer;
            buffer.write_var_int(packet.id());
            packet.write(buffer);
            return buffer;
        }


        friend class protocol;
    };
}

#endif // NETWORK_PACKETENCODER_HPP
