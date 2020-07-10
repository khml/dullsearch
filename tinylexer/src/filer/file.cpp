//
// Created by KHML on 2020/07/10.
//

#include <fstream>
#include <stdexcept>

#include <tinylexer/filer/file.hpp>

namespace tinylex
{
    std::vector<std::string> readFile(const std::string& filepath)
    {
        std::ifstream file(filepath);
        std::vector<std::string> lines;

        if (file.fail())
            throw std::runtime_error("Failed to open file : " + filepath);

        std::string line;
        while (getline(file, line))
            lines.emplace_back(line);

        return lines;
    }

    void writeLinesToFile(const std::string& filepath, const std::vector<std::string>& lines)
    {
        std::ofstream file(filepath);
        if (file.fail())
            throw std::runtime_error("Failed to open file : " + filepath);

        for (const std::string& line:lines)
        {
            file << line << std::endl;
        }
    }

    std::string readFileToStr(const std::string& filepath)
    {
        std::ifstream file(filepath);

        if (file.fail())
            throw std::runtime_error("Failed to open file : " + filepath);

        std::string result;
        std::string line;
        while (getline(file, line))
            result += " " + line;

        return result;
    }
}