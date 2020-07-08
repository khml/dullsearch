//
// Created by KHML on 2020/07/08.
//

#include <algorithm>
#include <iostream>
#include <utility>

#include <tinylexer/wordid/utilities.hpp>

namespace wordid
{
    void uniqSort(std::vector<size_t>& strContainer)
    {
        std::sort(strContainer.begin(), strContainer.end());
        auto last = std::unique(strContainer.begin(), strContainer.end());
        strContainer.erase(last, strContainer.end());
    }

    template<>
    void printVec(const std::vector<std::string>& container)
    {
        std::cout << "[ ";
        for (const std::string& word : container)
        {
            std::cout << '"' << word << '"';
            if (word != container.back())
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }

    std::string toStr(const std::vector<size_t>& ids)
    {
        std::string str;
        for (const size_t& id: ids)
        {
            str += std::to_string(id);
            if (id != ids.back())
                str += ", ";
        }
        return std::move(str);
    }
}