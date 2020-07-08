#include <tinylexer/lexer.hpp>
#include <wordid/table.hpp>

int main()
{
    std::vector<std::string> words = tinylex::toWords("Hello, World! This is a Hello World program");
    tinylex::printWords(words);

    wordid::WordIdTable table;
    auto ids = table.get_ids(words);
    table.print();
    wordid::printIds(ids);
    wordid::uniqSort(ids);
    wordid::printIds(ids);
    return 0;
}
