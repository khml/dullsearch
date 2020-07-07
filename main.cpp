#include <tinylexer/lexer.hpp>

int main()
{
    auto words = tinylex::toWords("Hello, World!");
    tinylex::printWords(words);
    return 0;
}
