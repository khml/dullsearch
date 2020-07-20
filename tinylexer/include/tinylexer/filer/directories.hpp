//
// Created by KHML on 2020/07/09.
//

#ifndef TINYLEXER_DIRECTORIES_HPP
#define TINYLEXER_DIRECTORIES_HPP

#include <string>
#include <vector>

namespace tinylex
{
    std::vector<std::string> listDir(const std::string& path);

    std::vector<std::string> listDirRecursive(const std::string& path);
}

#endif //TINYLEXER_DIRECTORIES_HPP
