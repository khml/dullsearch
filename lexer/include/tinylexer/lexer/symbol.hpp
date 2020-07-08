//
// Created by KHML on 2020/07/05.
//

#ifndef TINYLEXER_LEXER_SYMBOL_HPP
#define TINYLEXER_LEXER_SYMBOL_HPP

#include <map>
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

        Symbol toSymbol(const std::string& val);

        std::map<std::string, Symbol> toSymbolMap();
    }
}

#endif //TINYLEXER_LEXER_SYMBOL_HPP
