#include <iostream>

#include <tinylexer/lexer.hpp>
#include <tinylexer/wordid.hpp>
#include <tinylexer/filer.hpp>

int main()
{
    wordid::WordIdTable table;
    std::vector<std::string> words = tinylex::lex("Hello, World! This is a Hello World program");
    std::vector<std::size_t> ids = table.get_ids(words);
    wordid::uniqSort(ids);
    wordid::printVec(ids);
    std::cout << wordid::toStr(ids) << std::endl;
    tinylex::printStringVec(tinylex::listDir("."));
    return 0;
}
