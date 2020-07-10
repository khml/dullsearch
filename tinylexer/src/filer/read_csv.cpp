//
// Created by KHML on 2020/07/11.
//

#include <tinylexer/filer/read_csv.hpp>
#include <tinylexer/filer/file.hpp>
#include <tinylexer/filer/utilities.hpp>

namespace tinylex
{
    std::vector<std::vector<std::string>> readCsvFile(const std::string& filepath)
    {
        std::vector<std::vector<std::string>> csvData;

        std::vector<std::string> lines = readFile(filepath);
        csvData.reserve(lines.size());

        for (std::string& line:lines)
            csvData.emplace_back(splitByComma(line));

        return csvData;
    }
}
