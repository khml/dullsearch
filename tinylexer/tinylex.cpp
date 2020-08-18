//
// Created by KHML on 2020/07/15.
//

#include <iostream>
#include <string>

#include <tinylexer.hpp>

static const char* VERSION = "alpha-0.0.1";
static const char* APP_NAME = "TinyLex";
static const char* TINYLEX_FILENAME = ".tinylex.txt";

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

void showVersion()
{
    std::cout << APP_NAME << " version: " << VERSION << std::endl;
}

void showHelp()
{
    std::cout << "Usage: " << APP_NAME << "[options]" << "{ word | filepath }" << std::endl
              << "Options:" << std::endl
              << "-a <filepath>  Indexing the specified file" << std::endl
              << "-s <word>      Search file" << std::endl
              << "-v, --version  Display version info" << std::endl
              << "-h, --help     Display help" << std::endl;
}

void indexing(const std::string& filepath, tinylex::DocumentTable& table)
{
    table.setIds(filepath);
    table.dump(TINYLEX_FILENAME);
}

void search(const std::string& word, tinylex::DocumentTable& table)
{
    std::cout << "word: " << word << std::endl;
    for (const auto& filepath : table.lookupFiles(word))
    {
        std::cout << filepath << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: specify filename" << std::endl;
        return -1;
    }

    tinylex::DocumentTable docTable;
    docTable.restore(TINYLEX_FILENAME);

    for (int pos = 1; pos < argc; pos++)
    {
        CommandOption option = parseOption(argv, pos);
        if (option == Add && pos < argc)
        {
            indexing(argv[pos], docTable);
        }
        else if (option == Search || option == Other)
        {
            search(argv[pos], docTable);
        }
        else if (option == Version)
        {
            showVersion();
            break;
        }
        else if (option == Help)
        {
            showHelp();
            break;
        }
    }

    return 0;
}

