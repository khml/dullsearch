#include <iostream>

#include <tinylexer.hpp>
int main()
{
    std::vector<std::string> words = tinylex::lex("Hello, World! This is a Hello World program");

    tinylex::WordIdTable table; // create word id table
    std::vector<std::size_t> ids = table.getIdsWithUniqSort(words); // get ids from words
    tinylex::printVec(ids); // show ids
    table.print(); // show table

    const std::string filepath = "example.txt";
    table.dump(filepath);
    table.clear();
    table.print();
    table.restore(filepath);
    table.print();

    return 0;
}
