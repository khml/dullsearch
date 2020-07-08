//
// Created by KHML on 2020/07/07.
//

#ifndef TINYLEXER_LEXER_LEXER_HPP
#define TINYLEXER_LEXER_LEXER_HPP

#include <string>
#include <vector>

namespace tinylex
{
    std::vector<std::string> lex(const std::string& line);

    size_t readNumber(size_t indicator, const std::string& line, std::vector<std::string>& words);

    size_t readIdentifier(size_t indicator, const std::string& line, std::vector<std::string>& words);

    size_t readString(
        size_t indicator, const std::string& mark, std::vector<std::string>& words, const std::string& line);

    size_t readMultiCharOperator(size_t indicator, const std::string& line, std::vector<std::string>& words,
        const std::string& ch, size_t symSize);
}

#endif //TINYLEXER_LEXER_LEXER_HPP
