#include <tinylexer/lexer.hpp>
#include <wordid/container.hpp>

int main()
{
    std::vector<std::string> words = tinylex::toWords("Hello, World!");
    tinylex::printWords(words);
    wordid::Container container(words);
    container.print();
    return 0;
}
