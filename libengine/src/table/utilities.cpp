//
// Created by KHML on 2020/07/08.
//

#include <algorithm>
#include <iostream>
#include <utility>

#include <dullsearch/table/utilities.hpp>

namespace dullsearch
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
        for (size_t idx = 0; idx < container.size(); idx++)
        {
            std::cout << '"' << container[idx] << '"';
            if (idx < container.size() - 1)
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }

    std::string toStr(const std::vector<size_t>& ids)
    {
        std::string str;
        for (size_t idx = 0; idx < ids.size(); idx++)
        {
            str += std::to_string(ids[idx]);
            if (idx < ids.size() - 1)
                str += ", ";
        }
        return str;
    }
}