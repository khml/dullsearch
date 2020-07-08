//
// Created by KHML on 2020/07/06.
//

#ifndef TINYLEXER_UTILITIES_HPP
#define TINYLEXER_UTILITIES_HPP

namespace tinylex
{
    bool isDigit(const std::string& str);

    bool isFloat(const std::string& str);

    bool isDouble(const std::string& str);

    bool isIdentifier(const std::string& str);
}

#endif //TINYLEXER_UTILITIES_HPP
