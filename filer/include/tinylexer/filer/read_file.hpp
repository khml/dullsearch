//
// Created by KHML on 2020/07/10.
//

#ifndef TINYLEXER_READ_FILE_HPP
#define TINYLEXER_READ_FILE_HPP

#include <string>
#include <vector>

namespace tinylex
{
    std::vector<std::string> readFile(const std::string& filepath);

    std::string readFileToStr(const std::string& filepath);
}

#endif //TINYLEXER_READ_FILE_HPP
