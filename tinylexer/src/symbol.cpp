//
// Created by KHML on 2020/07/05.
//

#include <algorithm>

#include <tinylexer/symbol.hpp>

using std::string;

namespace tinylex
{
    namespace symbol
    {
        std::map<string, Symbol> toSymbolMap()
        {
            return std::map<string, Symbol>{
                {"+",  ADD},
                {"-",  SUB},
                {"*",  ASTERISK},
                {"/",  SLASH},
                {"@",  AT},
                {"=",  EQUAL},
                {")",  PARENTHESISE_RIGHT},
                {"(",  PARENTHESIS_LEFT},
                {"]",  BRACKET_RIGHT},
                {"[",  BRACKET_LEFT},
                {"}",  BRACE_RIGHT},
                {"{",  BRACE_LEFT},
                {".",  DOT},
                {",",  COMMA},
                {":",  COLON},
                {";",  SEMICOLON},
                {"?",  INTERROGATION},
                {">",  GRATER_THAN},
                {"<",  LESSER_THAN},
                {"\'", APOSTROPHE},
                {"\"", QUOTATION},
                {"&",  AMPERSAND},
                {"%",  PERCENT},
                {"$",  DOLLAR},
                {"#",  SHARP},
                {"|",  PIPE},
                {"_",  UNDER_BAR},
                {"\\", BACKSLASH},
                {" ",  WHITESPACE},
                {"\n", NEW_LINE},
                {"==", EQUIVALENCE},
                {">=", GRATER},
                {"<=", LESSER},
                {"++", INCREMENTAL},
                {"--", DECREMENTAL},
                {"&&", AND},
                {"||", OR},
                {"/*", COMMENT_START},
                {"*/", COMMENT_END},
                {"->", ARROW},
                {"=>", FAT_ARROW},
                {"!", EXCLAMATION},
            };
        }

        Symbol toSymbol(const string& val)
        {
            static std::map<string, Symbol> dictionary = symbol::toSymbolMap();

            auto iter = dictionary.find(val);
            if (iter != end(dictionary))
            {
                return iter->second;
            }
            else
            {
                return symbol::IDENTIFIER;
            }
        }
    }
}
