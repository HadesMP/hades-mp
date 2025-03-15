#ifndef NETWORK_PACKETREGISTRY_HPP
#define NETWORK_PACKETREGISTRY_HPP

#include <map>
#include <memory>
#include <functional>
#include <network/packet/packet.hpp>

namespace network {
    class packet_registry {
        using constructor_t = std::function<std::unique_ptr<packet>()>;

    public:
        std::unique_ptr<packet> construct_packet(const connection_state state, const int id) const {
            if (const auto it = _constructors.find({state, id}); it != _constructors.end()) {
                return it->second();
            }
            return nullptr;
        }

        template<typename packet_t, is_packet_t<packet_t>* = nullptr>
        void register_packet() {
            auto id = packet_t::_id_;
            auto state = packet_t::_state_;
            _constructors[{state, id}] = [] { return std::make_unique<packet_t>(); };
        }

        void register_packet(const connection_state state, const int id, const constructor_t &constructor) {
            _constructors[{state, id}] = constructor;
        }

    private:
        std::map<std::pair<connection_state, int>, constructor_t> _constructors;
    };
}

#endif // NETWORK_PACKETREGISTRY_HPP
