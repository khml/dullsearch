//
// Created by KHML on 2020/07/05.
//

#ifndef TINYLEXER_SYMBOL_HPP
#define TINYLEXER_SYMBOL_HPP

#include <string>
#include <vector>

namespace tinylex
{
    namespace symbol
    {
        enum Symbol
        {
        ADD, /* + */
        SUB, /* - */
        ASTERISK, /* * */
        SLASH, /* / */
        AT, /* @ */
        EQUAL, /* = */
        PARENTHESISE_RIGHT, /* ) */
        PARENTHESIS_LEFT, /* ( */
        BRACKET_RIGHT, /* ] */
        BRACKET_LEFT, /* [ */
        BRACE_RIGHT, /* } */
        BRACE_LEFT, /* { */
        DOT, /* . */
        COMMA, /* , */
        COLON, /* : */
        SEMICOLON, /* ; */
        INTERROGATION, /* ? */
        GRATER_THAN, /* > */
        LESSER_THAN, /* < */
        APOSTROPHE, /* \' */
        QUOTATION, /* \" */
        AMPERSAND, /* & */
        PERCENT, /* % */
        DOLLAR, /* $ */
        SHARP, /* # */
        PIPE, /* | */
        UNDER_BAR, /* _ */
        BACKSLASH, /* \\ */
        WHITESPACE, /*   */
        NEW_LINE, /* \n */
        EQUIVALENCE, /* == */
        GRATER, /* >= */
        LESSER, /* <= */
        INCREMENTAL, /* ++ */
        DECREMENTAL, /* -- */
        AND, /* && */
        OR, /* || */
        COMMENT_START, // /*
        COMMENT_END, // */
        ARROW, /* -> */
        FAT_ARROW, /* => */
        EXCLAMATION, /* ! */
        IDENTIFIER, /*  */
        };
    }

    symbol::Symbol toSymbol(const std::string& val);

    std::vector<std::string> toWords(const std::string& line);

    void printWords(const std::vector<std::string>& words);

    size_t readNumber(size_t indicator, const std::string& line, std::vector<std::string>& words);

    size_t readIdentifier(size_t indicator, const std::string& line, std::vector<std::string>& words);

    size_t readString(
        size_t indicator, const std::string& mark, std::vector<std::string>& words, const std::string& line);

    size_t readMultiCharOperator(size_t indicator, const std::string& line, std::vector<std::string>& words,
        const std::string& ch, size_t symSize);
}

#endif //TINYLEXER_SYMBOL_HPP
