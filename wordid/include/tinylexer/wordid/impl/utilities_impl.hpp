//
// Created by KHML on 2020/07/08.
//

#ifndef TINYLEXER_UTILITIES_IMPL_HPP
#define TINYLEXER_UTILITIES_IMPL_HPP

#include <iostream>

namespace tinylex
{
    template<typename T>
    void printVec(const std::vector<T>& container)
    {
        std::cout << "[ ";
        for (const T& item: container)
        {
            std::cout << item;
            if (item != container.back())
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
}

#endif //TINYLEXER_UTILITIES_IMPL_HPP
