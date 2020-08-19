//
// Created by KHML on 2020/07/09.
//

#include <sys/stat.h>

#include <dullsearch/filer/utilities.hpp>
#include <dullsearch/lexer/symbol.hpp>
#include <dullsearch/lexer/lexer.hpp>

namespace dullsearch
{
    mode_t getMode(const std::string& path)
    {
        struct ::stat st{};
        stat(path.c_str(), &st);
        return (st.st_mode & S_IFMT);
    }

    bool isExist(const std::string& path)
    {
        struct ::stat st{};
        return stat(path.c_str(), &st) == 0;
    }

    bool isDir(const std::string& path)
    {
        return (getMode(path) == S_IFDIR);
    }

    bool isReg(const std::string& path)
    {
        return (getMode(path) == S_IFREG);
    }

    bool createDir(const std::string& path)
    {
        return mkdir(path.c_str(), S_IRWXU) >= 0;
    }

    std::vector<std::string> splitByComma(const std::string& line)
    {
        std::vector<std::string> result;
        std::string ch;
        std::string elem;
        symbol::Symbol sym;
        bool isFirstChar = true;

        for (size_t pos = 0; pos < line.length(); pos++)
        {
            ch = line.substr(pos, 1);
            sym = symbol::toSymbol(ch);

            if (sym == symbol::WHITESPACE)
                continue;

            if (isFirstChar && (sym == symbol::QUOTATION || sym == symbol::APOSTROPHE))
            {
                readString(pos, line, result, ch);
                pos++;
                elem = "";
                isFirstChar = true;
                continue;
            }

            if (sym != symbol::COMMA)
            {
                elem += ch;
                isFirstChar = false;
                continue;
            }

            result.emplace_back(elem);
            elem = "";
            isFirstChar = true;
        }
        if (elem.length() > 0)
            result.emplace_back(elem);
        return result;
    }
}