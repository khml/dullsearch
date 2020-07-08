#include <tinylexer/lexer.hpp>
#include <tinylexer/wordid.hpp>

int main()
{
    std::vector<std::string> words = tinylex::lex("Hello, World! This is a Hello World program");
    wordid::printVec(words);

    wordid::WordIdTable table;
    auto ids = table.get_ids(words);
    table.print();
    wordid::printVec(ids);
    wordid::uniqSort(ids);
    wordid::printVec(ids);
    return 0;
}
