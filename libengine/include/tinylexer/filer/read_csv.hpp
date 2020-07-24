//
// Created by KHML on 2020/07/11.
//

#ifndef TINYLEXER_READ_CSV_HPP
#define TINYLEXER_READ_CSV_HPP

#include <string>
#include <vector>

namespace tinylex
{
    std::vector<std::vector<std::string>> readCsvFile(const std::string& filepath);
}

#endif //TINYLEXER_READ_CSV_HPP
