//
// Created by KHML on 2020/07/15.
//

#include <iostream>
#include <string>

#include <tinylexer.hpp>

enum CommandOption
{
    Add = 0,
    Search
};

CommandOption parseOption(char* argv[], int& pos)
{
    const std::string option(argv[pos]);
    if (option == "-a")
    {
        pos++;
        return Add;
    }
    return Search;
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
    else if (option == Search)
    {
        const std::string word = std::string(argv[pos]);
        for (const auto& filepath : docTable.lookupFiles(word))
        {
            std::cout << filepath << std::endl;
        }
    }

    return 0;
}

