//
// Created by KHML on 2020/07/07.
//

#ifndef TINYLEXER_LEXER_LEXER_HPP
#define TINYLEXER_LEXER_LEXER_HPP

#include <string>
#include <vector>

namespace dullsearch
{
    std::vector<std::string> lex(const std::string& line);

    void readNumber(size_t& indicator, const std::string& line, std::vector<std::string>& words);

    void readIdentifier(size_t& indicator, const std::string& line, std::vector<std::string>& words);

    void readString(
        size_t& indicator, const std::string& line, std::vector<std::string>& words, const std::string& mark);

    void readMultiCharOperator(size_t& indicator, const std::string& line, std::vector<std::string>& words,
        const std::string& ch, size_t symSize);
}

#endif //TINYLEXER_LEXER_LEXER_HPP
