//
// Created by KHML on 2020/07/15.
//

#include <iostream>
#include <string>

#include <tinylexer.hpp>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: specify filename" << std::endl;
        return -1;
    }

    const std::string DOC_FILENAME = ".doc.tinylex";
    const std::string WORD_FILENAME = ".word.tinylex";

    std::string filepath = std::string(argv[1]);
    tinylex::DocumentIdTable docTable(DOC_FILENAME, WORD_FILENAME);
    docTable.setIds(filepath);
    docTable.dump();

    return 0;
}

