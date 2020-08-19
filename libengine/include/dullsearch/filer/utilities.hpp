//
// Created by KHML on 2020/07/09.
//

#ifndef TINYLEXER_UTILITIES_HPP
#define TINYLEXER_UTILITIES_HPP

#include <string>
#include <vector>

namespace dullsearch
{
    bool isExist(const std::string& path);

    bool isDir(const std::string& path);

    bool isReg(const std::string& path);

    bool createDir(const std::string& path);

    std::vector<std::string> splitByComma(const std::string& line);
}

#endif //TINYLEXER_UTILITIES_HPP
