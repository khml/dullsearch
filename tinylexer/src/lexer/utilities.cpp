//
// Created by KHML on 2020/07/06.
//

#include <iostream>
#include <regex>
#include <string>

#include <tinylexer/lexer/utilities.hpp>

using std::regex;
using std::string;

namespace tinylex
{
    bool isDigit(const string& str)
    {
        static regex re("[0-9]+");
        return regex_match(str, re);
    }

    bool isFloat(const string& str)
    {
        static regex re(R"(^(\d*[\\.]\d*)f$)");
        return regex_match(str, re);
    }

    bool isDouble(const string& str)
    {
        static regex re(R"(^(\d*[\.]\d*)$)");
        return regex_match(str, re);
    }

    bool isIdentifier(const string& str)
    {
        static regex re("[_a-zA-Z][_a-zA-Z0-9]?");
        return regex_match(str, re);
    }
}