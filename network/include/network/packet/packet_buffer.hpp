#ifndef NETWORK_PACKETBUFFER_HPP
#define NETWORK_PACKETBUFFER_HPP

#include <locale>
#include <asio/buffer.hpp>

namespace network {
    class packet_buffer {
    public:
        auto data() const {
            return _data;
        }

        void write_byte(const uint8_t value) {
            _data.push_back(value);
        }

        uint8_t read_byte() {
            if (_read_position >= _data.size()) {
                throw std::out_of_range("Read position out of range");
            }

            return _data[_read_position++];
        }

        void write_bytes(const std::vector<uint8_t> &bytes) {
            _data.insert(_data.end(), bytes.begin(), bytes.end());
        }

        std::vector<uint8_t> read_bytes(const size_t length) {
            if (_read_position + length > _data.size()) {
                throw std::out_of_range("Read position out of range");
            }

            const auto data_len = static_cast<ptrdiff_t>(length);
            const auto read_pos = static_cast<ptrdiff_t>(_read_position);
            const auto data_start = _data.begin() + read_pos;

            std::vector result(data_start, data_start + data_len);
            _read_position += length;

            return result;
        }

        void write_short(const int16_t value) {
            write_byte(static_cast<uint8_t>(value >> 8 & 0xFF));
            write_byte(static_cast<uint8_t>(value & 0xFF));
        }

        int16_t read_short() {
            return static_cast<int16_t>(read_byte() << 8 | read_byte());
        }

        void write_int(const int32_t value) {
            write_byte(static_cast<uint8_t>(value >> 24 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 16 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 8 & 0xFF));
            write_byte(static_cast<uint8_t>(value & 0xFF));
        }

        int32_t read_int() {
            return read_byte() << 24 | read_byte() << 16 | read_byte() << 8 | read_byte();
        }

        void write_long(const int64_t value) {
            write_byte(static_cast<uint8_t>(value >> 56 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 48 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 40 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 32 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 24 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 16 & 0xFF));
            write_byte(static_cast<uint8_t>(value >> 8 & 0xFF));
            write_byte(static_cast<uint8_t>(value & 0xFF));
        }

        int64_t read_long() {
            return static_cast<int64_t>(read_byte()) << 56 |
                   static_cast<int64_t>(read_byte()) << 48 |
                   static_cast<int64_t>(read_byte()) << 40 |
                   static_cast<int64_t>(read_byte()) << 32 |
                   static_cast<int64_t>(read_byte()) << 24 |
                   static_cast<int64_t>(read_byte()) << 16 |
                   static_cast<int64_t>(read_byte()) << 8 |
                   read_byte();
        }

        void write_float(const float value) {
            uint32_t intValue;
            std::memcpy(&intValue, &value, sizeof(value));
            write_int(static_cast<int32_t>(intValue));
        }

        float read_float() {
            const auto int_value = static_cast<uint32_t>(read_int());
            float float_value;
            std::memcpy(&float_value, &int_value, sizeof(int_value));
            return float_value;
        }

        void write_double(const double value) {
            uint64_t long_value;
            std::memcpy(&long_value, &value, sizeof(value));
            write_long(static_cast<int64_t>(long_value));
        }

        double read_double() {
            const auto long_value = static_cast<uint64_t>(read_long());
            double double_value;
            std::memcpy(&double_value, &long_value, sizeof(long_value));
            return double_value;
        }

        std::string read_string() {
            const auto length = read_var_int();
            std::vector<uint8_t> bytes = read_bytes(length);
            return {bytes.begin(), bytes.end()};
        }

        void write_string(const std::string &value) {
            write_var_int(static_cast<int32_t>(value.length()));
            write_bytes(std::vector<uint8_t>(value.begin(), value.end()));
        }

        void write_var_int(int32_t value) {
            while (true) {
                if ((value & ~0x7F) == 0) {
                    write_byte(static_cast<uint8_t>(value));
                    return;
                }
                write_byte(static_cast<uint8_t>((value & 0x7F) | 0x80));
                value >>= 7;
            }
        }

        int32_t read_var_int() {
            int32_t result = 0;
            int shift = 0;
            while (true) {
                const uint8_t b = read_byte();
                result |= (b & 0x7F) << shift;
                if ((b & 0x80) == 0) {
                    return result;
                }
                shift += 7;
                if (shift > 35) {
                    throw std::runtime_error("VarInt too big");
                }
            }
        }

        void write_var_long(int64_t value) {
            while (value & ~0x7F) {
                write_byte(static_cast<uint8_t>(value & 0x7F | 0x80));
                value >>= 7;
            }

            write_byte(static_cast<uint8_t>(value));
        }

        int64_t read_var_long() {
            int64_t result = 0;
            int shift = 0;
            while (true) {
                const uint8_t b = read_byte();
                result |= static_cast<int64_t>(b & 0x7F) << shift;
                if ((b & 0x80) == 0) {
                    return result;
                }
                shift += 7;
                if (shift > 63) {
                    throw std::runtime_error("VarLong too big");
                }
            }
        }

        void read(const asio::mutable_buffer& buf) {
            const auto data_ptr = static_cast<uint8_t*>(buf.data());
            _data.assign(data_ptr, data_ptr + buf.size());
        }

        void write(const asio::mutable_buffer& buf) const {
            const auto size = std::min(_data.size(), buf.size());
            std::memcpy(buf.data(), _data.data(), size);
        }

        lua_State* read_lua_state() {
            return nullptr;
        }

        void write_lua_state(lua_State* state) {
            return;
        }

    private:
        std::vector<uint8_t> _data;
        size_t _read_position = 0;
    };
}

#endif // NETWORK_PACKETBUFFER_HPP
