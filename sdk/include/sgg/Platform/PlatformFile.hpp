//
// Created by Decencies on 19/08/2024.
//

#ifndef PLATFORMFILE_HPP
#define PLATFORMFILE_HPP

#include "sdk/sym/defs.hpp"

namespace sgg {
    static constexpr sdk::pdb_global_func<"PlatformFile::CreateStreamWithRetry", bool> CreateStreamWithRetry_func;
    static sdk::pdb_sym_tree PlatformFile_tree {
        &CreateStreamWithRetry_func,
    };
}

#endif //PLATFORMFILE_HPP
