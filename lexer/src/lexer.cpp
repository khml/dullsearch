//
// Created by KHML on 2020/07/07.
//

#include <stdexcept>

#include <tinylexer/lexer/lexer.hpp>
#include <tinylexer/lexer/symbol.hpp>
#include <tinylexer/lexer/utilities.hpp>

using std::string;

namespace tinylex
{
    std::vector<std::string> lex(const string& line)
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
                        readNumber(indicator, line, words);
                    else
                        readIdentifier(indicator, line, words);
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
        return words;
    }

    void readNumber(size_t& indicator, const string& line, std::vector<string>& words)
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
    }

    void readIdentifier(size_t& indicator, const string& line, std::vector<string>& words)
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
        words.emplace_back(line.substr(start, (indicator - start + 1)));
    }

    void readString(size_t& indicator, const string& line, std::vector<string>& words, const std::string& mark)
    {
        int start = indicator++;
        for (; indicator < line.size(); indicator++)
        {
            auto ch = line.substr(indicator, 1);
            if (mark == ch)
            {
                auto str = line.substr(start + 1, (indicator - start - 1));
                words.emplace_back(str);
                return;
            }
        }
        throw std::runtime_error("expected : " + mark + " but not given.");
    }

    void readMultiCharOperator(size_t& indicator, const string& line, std::vector<string>& words,
        const std::string& ch, const size_t symSize)
    {
        if (indicator + symSize - 1 >= line.size())
            return;

        auto multiCharOp = line.substr(indicator, symSize);

        if (symbol::toSymbol(multiCharOp) == symbol::IDENTIFIER)
            multiCharOp = ch; // rollback
        else
            indicator++;

        words.emplace_back(std::move(multiCharOp));
    }
}