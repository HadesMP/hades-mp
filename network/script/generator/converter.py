def lua_type_to_cpp_type(lua_type: str) -> str:
    type_mapping = {
        "string": "std::string",
        "number": "double",
        "integer": "int",
        "boolean": "bool",
        "any": "lua_State*",
        "table": "std::map<std::string, std::any>",
        "function": "std::function<void()>",
        "nil": "std::optional<std::any>"
    }

    return type_mapping.get(lua_type, lua_type)


def lua_type_to_buffer_read_method(lua_type: str) -> str:
    method_mapping = {
        "string": "read_string",
        "number": "read_double",
        "integer": "read_int",
        "boolean": "read_bool",
        "any": "read_lua_state",
        "table": "read_nbt"
    }

    return method_mapping.get(lua_type, f"read_{lua_type.lower()}")


def lua_type_to_buffer_write_method(lua_type: str) -> str:
    method_mapping = {
        "string": "write_string",
        "number": "write_double",
        "integer": "write_int",
        "boolean": "write_bool",
        "any": "write_lua_state",
        "table": "write_nbt"
    }

    return method_mapping.get(lua_type, f"write_{lua_type.lower()}")


def field_name_to_member_name(field_name: str) -> str:
    return f"_{field_name.lower()}"
