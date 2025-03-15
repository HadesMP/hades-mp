from .model import LuaClass, LuaField
from .parser import parse_lua_doc
from .converter import (
    lua_type_to_cpp_type,
    lua_type_to_buffer_read_method,
    lua_type_to_buffer_write_method
)
from .generator import generate_cpp_class, generate_cpp_header

def process_lua_doc_file(input_file: str, output_file: str = None):
    with open(input_file, 'r') as f:
        content = f.read()

    lua_classes = parse_lua_doc(content)
    cpp_code = generate_cpp_header(lua_classes)

    if output_file:
        with open(output_file, 'w') as f:
            f.write(cpp_code)
        print(f"Generated.")
    else:
        print(cpp_code)
