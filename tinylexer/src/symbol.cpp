//
// Created by KHML on 2020/07/05.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

#include <tinylexer/symbol.hpp>
#include <tinylexer/utilities.hpp>

using std::string;

using tinylex::symbol::Symbol;

namespace tinylex
{
    namespace symbol
    {
        static std::map<string, Symbol> toSymbolMap()
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

    std::vector<std::string> toWords(const string& line)
    {
        std::vector<string> words;

        string ch;
        Symbol sym;

        for (size_t indicator = 0; indicator < line.size(); indicator++)
        {
            ch = line.substr(indicator, 1);
            sym = toSymbol(ch);
            switch (sym)
            {
                case symbol::IDENTIFIER:
                    if (isDigit(ch))
                        indicator = readNumber(indicator, line, words);
                    else
                        indicator = readIdentifier(indicator, line, words);
                    break;
                case symbol::WHITESPACE:
                    break;
                case symbol::ADD:
                case symbol::SUB:
                case symbol::ASTERISK:
                case symbol::SLASH:
                case symbol::EQUAL:
                case symbol::GRATER_THAN:
                case symbol::LESSER_THAN:
                case symbol::AMPERSAND:
                case symbol::PIPE:
                    readMultiCharOperator(indicator, line, words, ch, 2);
                    break;
                case symbol::APOSTROPHE:
                case symbol::QUOTATION:
                    readString(indicator, line, words, ch);
                    break;
                default:
                    words.emplace_back(ch);
                    break;
            }
        }
        return std::move(words);
    }

    size_t readNumber(size_t indicator, const string& line, std::vector<string>& words)
    {
        int start = indicator;
        bool isDotAppeared = false;
        std::string ch;
        for (; indicator < line.size(); indicator++)
        {
            ch = line.substr(indicator, 1);
            if (ch == ".")
            {
                // allow dot only once
                if (isDotAppeared)
                    break;
                isDotAppeared = true;
            }
            else if (isDigit(ch))
                continue;
            else if (ch == "f")
            {
                indicator++;
                break;
            }
            else
                break;
        }
        ch = line.substr(start, indicator - start);
        --indicator;
        words.emplace_back(std::move(ch));
        return indicator;
    }

    size_t readIdentifier(size_t indicator, const string& line, std::vector<string>& words)
    {
        int start = indicator++;
        for (; indicator < line.size(); indicator++)
        {
            if (toSymbol(line.substr(indicator, 1)) != symbol::IDENTIFIER)
            {
                --indicator;
                break;
            }
        }
        words.emplace_back(std::move(line.substr(start, (indicator - start + 1))));
        return indicator;
    }

    size_t readString(size_t indicator, const string& line, std::vector<string>& words, const std::string& mark)
    {
        int start = indicator++;
        for (; indicator < line.size(); indicator++)
        {
            auto ch = line.substr(indicator, 1);
            if (ch == "\\")
            {
                indicator++;
                continue;
            }
            if (ch == mark)
            {
                words.emplace_back(line.substr(start + 1, (indicator - start - 1)));
                return indicator;
            }
        }
        throw ("expected : " + mark + " but not given.");
    }

    size_t readMultiCharOperator(size_t indicator, const string& line, std::vector<string>& words,
        const std::string& ch, const size_t symSize)
    {
        if (indicator + symSize - 1 >= line.size())
            return indicator;

        auto multiCharOp = line.substr(indicator, symSize);

        if (toSymbol(multiCharOp) == symbol::IDENTIFIER)
            multiCharOp = ch; // rollback
        else
            indicator++;

        words.emplace_back(std::move(multiCharOp));
        return indicator;
    }

    void printWords(const std::vector<std::string>& words)
    {
        std::cout << "[ ";
        for(const std::string& word : words)
        {
            std::cout << "\"" << word << "\"";
            if (word != words.back())
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
}
