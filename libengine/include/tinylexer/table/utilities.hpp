//
// Created by KHML on 2020/07/08.
//

#ifndef TINYLEXER_TABLE_UTILITIES_HPP
#define TINYLEXER_TABLE_UTILITIES_HPP

#include <string>
#include <vector>

namespace tinylex
{
    void uniqSort(std::vector<size_t>& strContainer);

    std::string toStr(const std::vector<size_t>& ids);

    template<typename T>
    void printVec(const std::vector<T>& container);

    template<>
    void printVec(const std::vector<std::string>& container);
}

#include <tinylexer/table/impl/utilities_impl.hpp>

#endif //TINYLEXER_TABLE_UTILITIES_HPP
