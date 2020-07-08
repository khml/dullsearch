//
// Created by KHML on 2020/07/07.
//

#include <iostream>

#include <tinylexer/lexer/lexer.hpp>
#include <tinylexer/lexer/symbol.hpp>
#include <tinylexer/lexer/utilities.hpp>

using std::string;

namespace tinylex
{
    std::vector<std::string> toWords(const string& line)
    {
        std::vector<string> words;

        string ch;
        symbol::Symbol sym;

        for (size_t indicator = 0; indicator < line.size(); indicator++)
        {
            ch = line.substr(indicator, 1);
            sym = symbol::toSymbol(ch);
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
            if (symbol::toSymbol(line.substr(indicator, 1)) != symbol::IDENTIFIER)
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

        if (symbol::toSymbol(multiCharOp) == symbol::IDENTIFIER)
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
            std::cout << '"' << word << '"';
            if (word != words.back())
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
}