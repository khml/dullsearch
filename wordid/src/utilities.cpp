//
// Created by KHML on 2020/07/08.
//

#include <algorithm>

#include <tinylexer/wordid/utilities.hpp>

namespace wordid
{
    void uniqSort(std::vector<size_t>& strContainer)
    {
        std::sort(strContainer.begin(), strContainer.end());
        auto last = std::unique(strContainer.begin(), strContainer.end());
        strContainer.erase(last, strContainer.end());
    }
}