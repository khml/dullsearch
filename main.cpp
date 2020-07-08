#include <tinylexer/lexer.hpp>
#include <wordid/container.hpp>

int main()
{
    std::vector<std::string> words = tinylex::toWords("Hello, World! This is a Hello World program");
    tinylex::printWords(words);

    wordid::Container container;
    auto ids = container.get_ids(words);
    container.print();
    wordid::printIds(ids);
    wordid::uniqSort(ids);
    wordid::printIds(ids);
    return 0;
}
