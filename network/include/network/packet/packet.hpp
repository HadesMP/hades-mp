#ifndef NETWORK_PACKET_HPP
#define NETWORK_PACKET_HPP

#include <lua/lua.h>
#include <network/packet/packet_buffer.hpp>

namespace network {
    enum connection_state {
        handshake = -1,
        status,
        login,
        play
    };

    enum packet_direction {
        serverbound,
        clientbound
    };

    class packet {
    public:
        virtual ~packet() = default;

        virtual int id() const = 0;

        virtual void read(packet_buffer &buffer) = 0;

        virtual void write(packet_buffer &buffer) const = 0;

        virtual void handle() = 0;

        virtual connection_state state() const = 0;

        virtual packet_direction direction() const = 0;
    };

    template<connection_state _state, int _id>
    class s2c_packet : public packet {
    public:
        static constexpr int _id_ = _id;
        static constexpr int _state_ = _state;

        int id() const override {
            return _id;
        }

        connection_state state() const override {
            return _state;
        }

        packet_direction direction() const override {
            return clientbound;
        }
    };

    template<connection_state _state, int _id>
    class c2s_packet : public packet {
    public:
        static constexpr int _id_ = _id;
        static constexpr int _state_ = _state;

        int id() const override {
            return _id;
        }

        connection_state state() const override {
            return _state;
        }

        packet_direction direction() const override {
            return serverbound;
        }
    };

    template<typename packet_t>
    using is_packet_t = std::enable_if_t<std::is_base_of_v<packet, packet_t> >;
}

#endif // NETWORK_PACKET_HPP
