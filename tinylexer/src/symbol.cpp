//
// Created by KHML on 2020/07/05.
//

#include <algorithm>
#include <vector>

#include <tinylexer/symbol.hpp>

namespace tinylex
{
    size_t is_symbol(const std::string& str)
    {
        static std::vector<std::string> symbol{"+", "-", "*", "/", "@", "=", ")", "(", "]", "[", "}", "{", ".", ",",
                                               ":", ";", "?", ">", "<", "\'", "\"", "&", "%", "$", "#", "|", "_", "\\",
                                               " ", "\n", "==", ">=", "<=", "++", "--", "&&", "||", "/*", "*/", "->",
                                               "=>"};

        auto result = std::find(symbol.begin(), symbol.end(), str);
        if (result == symbol.end())
            return -1;

        return std::distance(symbol.begin(), result);
    }
}
