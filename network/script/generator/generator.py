import re
from typing import List
from .model import LuaClass
from .converter import (
    lua_type_to_cpp_type,
    lua_type_to_buffer_read_method,
    lua_type_to_buffer_write_method,
    field_name_to_member_name
)


def generate_cpp_class(lua_class: LuaClass) -> str:
    # noinspection PyListCreation
    cpp_code = []

    cpp_code.append("/**")
    cpp_code.append(f" * {lua_class.description}")
    cpp_code.append(" */")

    namespace_parts = lua_class.name.split('.')
    full_class_name = namespace_parts[-1]

    words = re.findall('[A-Z][a-z]*', full_class_name)
    class_name = '_'.join([w.lower() for w in words])

    packet_direction = "c2s" if "C2S" in lua_class.name else "s2c"

    state = lua_class.state or "play"
    packet_id = lua_class.id or "0"

    cpp_code.append(
        f"class {packet_direction}_{class_name} : public {packet_direction}_packet<{state}, {packet_id}> {{")
    cpp_code.append("public:")

    cpp_code.append("    void read(packet_buffer &buffer) override {")
    for field in lua_class.fields:
        member_name = field_name_to_member_name(field.name)
        read_method = lua_type_to_buffer_read_method(field.type)
        cpp_code.append(f"        {member_name} = buffer.{read_method}();")
    cpp_code.append("    }")
    cpp_code.append("")

    cpp_code.append("    void write(packet_buffer &buffer) const override {")
    for field in lua_class.fields:
        member_name = field_name_to_member_name(field.name)
        write_method = lua_type_to_buffer_write_method(field.type)
        cpp_code.append(f"        buffer.{write_method}({member_name});")
    cpp_code.append("    }")
    cpp_code.append("")

    cpp_code.append("private:")
    for field in lua_class.fields:
        member_name = field_name_to_member_name(field.name)
        cpp_type = lua_type_to_cpp_type(field.type)

        default_init = ""
        if cpp_type.endswith('*'):
            default_init = "{nullptr}"

        cpp_code.append(f"    {cpp_type} {member_name}{default_init}; // {field.description}")

    cpp_code.append("};")
    return "\n".join(["\t" + s for s in cpp_code])


def generate_cpp_header(lua_classes: List[LuaClass]) -> str:
    # noinspection PyListCreation
    cpp_code = []

    cpp_code.append("#ifndef NETWORK_PACKETS_HPP")
    cpp_code.append("#define NETWORK_PACKETS_HPP")
    cpp_code.append("")
    cpp_code.append("#include <network/packet/packet.hpp>")
    cpp_code.append("")
    cpp_code.append("namespace network {")

    for lua_class in lua_classes:
        cpp_code.append(generate_cpp_class(lua_class))
        cpp_code.append("")
    cpp_code.append("};")
    cpp_code.append("")

    cpp_code.append("#endif // NETWORK_PACKETS_HPP")

    return "\n".join(cpp_code)
