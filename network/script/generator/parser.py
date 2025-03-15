import re
from typing import List
from .model import LuaClass, LuaField


def parse_lua_doc(content: str) -> List[LuaClass]:
    classes = []

    class_blocks = re.split(r'---\s*\n(?=---)', content)

    for block in class_blocks:
        if not block.strip():
            continue

        class_obj = LuaClass("")

        description_lines = []
        for line in block.split('\n'):
            line = line.strip()
            if line.startswith('---') and not line.startswith('---@'):
                desc = line.replace('---', '', 1).strip()
                if desc:
                    description_lines.append(desc)
            elif not line.startswith('---'):
                break

        class_obj.description = ' '.join(description_lines)

        class_match = re.search(r'---@class\s+(\S+)', block)
        if class_match:
            class_obj.name = class_match.group(1)
        else:
            continue

        id_match = re.search(r'---@id\s+(\S+)', block)
        if id_match:
            class_obj.id = id_match.group(1)

        state_match = re.search(r'---@state\s+(\S+)', block)
        if state_match:
            class_obj.state = state_match.group(1)

        field_matches = re.finditer(r'---@field\s+(\S+)\s+(\S+)\s*(.*)', block)
        for match in field_matches:
            field_name = match.group(1)
            field_type = match.group(2)
            field_desc = match.group(3).strip()
            class_obj.fields.append(LuaField(field_name, field_type, field_desc))

        if class_obj.name:
            classes.append(class_obj)

    return classes
