#include <iostream>

#include <tinylexer.hpp>
int main()
{
    std::vector<std::string> words = tinylex::lex("Hello, World! This is a Hello World program");
    tinylex::printVec(words); // show lexing result

    tinylex::WordIdTable table; // create word id table
    std::vector<std::size_t> ids = table.getIds(words); // get ids from words
    tinylex::uniqSort(ids); //sort and uniq vector of id
    tinylex::printVec(ids); // show ids
    std::cout << tinylex::toStr(ids) << std::endl;

    tinylex::printVec(tinylex::listDir(".")); // show current dir
    std::string content = tinylex::readFileToStr("Makefile");
    ids = table.getIdsWithUniqSort(tinylex::lex(content));
    tinylex::printVec(ids); // show ids
    return 0;
}
