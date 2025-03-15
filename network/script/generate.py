"""
Generate C++ packet header files from the Lua definitions.
"""

import os
import sys

from generator.__main__ import process_lua_doc_file

# Add parent directory to sys.path to allow importing the package
sys.path.insert(0, os.path.abspath(os.path.dirname(__file__)))

process_lua_doc_file('./shared/Network.lua', '../include/network/protocol/packets.hpp')
