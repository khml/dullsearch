//
// Created by KHML on 2020/07/08.
//

#include <algorithm>
#include <iostream>

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
}