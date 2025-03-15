from dataclasses import dataclass
from typing import List, Optional


@dataclass
class LuaField:
    name: str
    type: str
    description: str


@dataclass
class LuaClass:
    name: str
    id: Optional[str] = None
    state: Optional[str] = None
    description: str = ""
    fields: List[LuaField] = None

    def __post_init__(self):
        if self.fields is None:
            self.fields = []
