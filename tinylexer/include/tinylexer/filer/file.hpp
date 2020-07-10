//
// Created by KHML on 2020/07/10.
//

#ifndef TINYLEXER_FILE_HPP
#define TINYLEXER_FILE_HPP

#include <string>
#include <vector>

namespace tinylex
{
    std::vector<std::string> readFile(const std::string& filepath);

    void writeLinesToFile(const std::string& filepath, const std::vector<std::string>& lines);

    std::string readFileToStr(const std::string& filepath);
}

#endif //TINYLEXER_FILE_HPP
