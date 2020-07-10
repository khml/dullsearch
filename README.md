# tinylexer

example code

```cpp
// main.cpp

#include <iostream>

#include <tinylexer/lexer.hpp>
#include <tinylexer/wordid.hpp>
#include <tinylexer/filer.hpp>

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

```

Run result.
```
[ "Hello", ",", "World", "!", "This", "is", "a", "Hello", "World", "program" ]
[ 1, 2, 3, 4, 5, 6, 7, 8 ]
1, 2, 3, 4, 5, 6, 7, 8
[ ".", "..", "example.cbp", "CMakeFiles", "Makefile", "example", "cmake_install.cmake" ]
```
