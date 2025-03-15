#ifndef NETWORK_PROTOCOL_HPP
#define NETWORK_PROTOCOL_HPP

#include <network/packet/packet_registry.hpp>

namespace network {
    class protocol {
    protected:
        protocol() = default;

    public:
        //protocol(protocol &other) = delete;

        void operator=(const protocol &) = delete;

        packet_registry registry() const {
            return _registry;
        }

        connection_state state() const {
            return _state;
        }

        void state(const connection_state state) {
            _state = state;
        }

        static const protocol &instance() {
            static protocol instance;
            return instance;
        }

    private:
        const packet_registry _registry{};
        connection_state _state{handshake};
    };
}

#endif // NETWORK_PROTOCOL_HPP
