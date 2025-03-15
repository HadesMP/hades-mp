#ifndef NETWORK_PACKETS_HPP
#define NETWORK_PACKETS_HPP

#include <network/packet/packet.hpp>

namespace network {
	/**
	 * 
	 */
	class c2s_custom_payload : public c2s_packet<play, 0> {
	public:
	    void read(packet_buffer &buffer) override {
	        _channel = buffer.read_string();
	        _content = buffer.read_lua_state();
	    }
	
	    void write(packet_buffer &buffer) const override {
	        buffer.write_string(_channel);
	        buffer.write_lua_state(_content);
	    }
	
	private:
	    std::string _channel; // The channel for the custom payload
	    lua_State* _content{nullptr}; // The payload content
	};

	/**
	 * 
	 */
	class s2c_custom_payload : public s2c_packet<play, 1> {
	public:
	    void read(packet_buffer &buffer) override {
	        _channel = buffer.read_string();
	        _content = buffer.read_lua_state();
	    }
	
	    void write(packet_buffer &buffer) const override {
	        buffer.write_string(_channel);
	        buffer.write_lua_state(_content);
	    }
	
	private:
	    std::string _channel; // The channel for the custom payload
	    lua_State* _content{nullptr}; // The payload content
	};

};

#endif // NETWORK_PACKETS_HPP