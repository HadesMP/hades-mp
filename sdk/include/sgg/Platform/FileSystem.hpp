#ifndef ENGINE_FILESYSTEM_HPP
#define ENGINE_FILESYSTEM_HPP

#include "sdk/sym/defs.hpp"

namespace sgg {
    static constexpr sdk::pdb_global_field<"gSystemFileIO", void*> gSystemFileIO_field;
    static constexpr sdk::pdb_global_func<"fsSetPathForResourceDir", void> fsSetPathForResourceDir_func;
    static constexpr sdk::pdb_global_func<"sgg::IsContentFolderModified", bool> IsContentFolderModified_func;
    static sdk::pdb_sym_tree FileSystem_tree {
        &gSystemFileIO_field,
        &fsSetPathForResourceDir_func,
        &IsContentFolderModified_func
    };

    enum ResourceMount : uint32_t {};

    enum FileMode : uint32_t {
        FM_READ = 0x1,
        FM_WRITE = 0x2,
        FM_APPEND = 0x4,
        FM_BINARY = 0x8,
        FM_ALLOW_READ = 0x10,
        FM_READ_WRITE = 0x3,
        FM_READ_APPEND = 0x5,
        FM_WRITE_BINARY = 0xa,
        FM_READ_BINARY = 0x9,
        FM_APPEND_BINARY = 0xc,
        FM_READ_WRITE_BINARY = 0xb,
        FM_READ_APPEND_BINARY = 0xd,
        FM_WRITE_ALLOW_READ = 0x12,
        FM_APPEND_ALLOW_READ = 0x14,
        FM_READ_WRITE_ALLOW_READ = 0x13,
        FM_READ_APPEND_ALLOW_READ = 0x15,
        FM_READ_BINARY_ALLOW_READ = 0x19,
        FM_WRITE_BINARY_ALLOW_READ = 0x1a,
        FM_APPEND_BINARY_ALLOW_READ = 0x1c,
        FM_READ_WRITE_BINARY_ALLOW_READ = 0x1b,
        FM_READ_APPEND_BINARY_ALLOW_READ = 0x1d
    };

    enum ResourceDirectory : uint32_t {
        // content files
        RD_MIDDLEWARE_2 = 0xe,
        RD_CODE = 0x27
    };
}

#endif //ENGINE_FILESYSTEM_HPP
