//
// Created by KHML on 2020/07/15.
//

#include <iostream>
#include <string>

#include <tinylexer.hpp>

static const char* VERSION = "alpha-0.0.1";
static const char* APP_NAME = "TinyLex";

enum CommandOption
{
    Add = 0,
    Help,
    Search,
    Version,
    Other
};

CommandOption parseOption(char* argv[], int& pos)
{
    const std::string option(argv[pos]);

    if (option == "-a")
    {
        pos++;
        return Add;
    }

    if (option == "-h" || option == "--help")
    {
        return Help;
    }

    if (option == "-v" || option == "--version")
    {
        return Version;
    }

    if (option == "-s")
    {
        pos++;
        return Search;
    }

    return Other;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: specify filename" << std::endl;
        return -1;
    }

    int pos = 1;
    CommandOption option = parseOption(argv, pos);

    const std::string TINYLEX_FILENAME = ".tinylex.txt";

    tinylex::DocumentIdTable docTable;
    docTable.restore(TINYLEX_FILENAME);

    if (option == Add && pos < argc)
    {
        std::string filepath = std::string(argv[pos]);
        docTable.setIds(filepath);
        docTable.dump(TINYLEX_FILENAME);
    }
    else if (option == Version)
    {
        std::cout << APP_NAME << " version: " << VERSION << std::endl;
    }
    else if (option == Help)
    {
        std::cout << "Usage: " << APP_NAME << "[options]" << "{ word | filepath }" << std::endl
                  << "Options:" << std::endl
                  << "-a <filepath>  Indexing the specified file" << std::endl
                  << "-s <word>      Search file" << std::endl
                  << "-v, --version  Display version info" << std::endl
                  << "-h, --help     Display help" << std::endl;
    }
    else if (option == Search || option == Other)
    {
        const std::string word = std::string(argv[pos]);
        for (const auto& filepath : docTable.lookupFiles(word))
        {
            std::cout << filepath << std::endl;
        }
    }

    return 0;
}

