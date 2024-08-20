#ifndef NET_MESSAGES_HPP
#define NET_MESSAGES_HPP

#include <cstdint>
#include <string>
#include <asio.hpp>

namespace net {
    enum class message_id : uint8_t {
        connect = 0,
        disconnect = 1,
    };

    struct client_t {
        uint8_t mId;
    };

    class net_message_t {
    public:
        virtual message_id id() const = 0;
    };

    class socket_t {
    public:
        uint8_t _read_raw[0x400]{};
        uint8_t _write_raw[0x400]{};
        asio::mutable_buffer _read_buffer{_read_raw, 0x400};
        asio::mutable_buffer _write_buffer{_write_raw, 0x400};
    };



    // sent to other clients when a player connects
    class connect_msg_t : public net_message_t {
        message_id id() const override {
            return message_id::connect;
        }
    };

    // sent/recieved to other clients when a player disconnects
    class disconnect_msg_t {
    };
}

#endif //NET_MESSAGES_HPP
