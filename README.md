# tinylexer

![ubuntu18.04](https://github.com/khml/tinylexer/workflows/ubuntu18.04/badge.svg)

[![CodeFactor](https://www.codefactor.io/repository/github/khml/tinylexer/badge)](https://www.codefactor.io/repository/github/khml/tinylexer)[![BCH compliance](https://bettercodehub.com/edge/badge/khml/tinylexer?branch=stable)](https://bettercodehub.com/)

# dependencies
- GCC 8.0 and more
- [GoogleTest](https://github.com/google/googletest) (only when run test)

# build

```
$ git clone https://github.com/khml/tinylexer.git
$ cd tinylexer
$ mkdir build && cd build
$ make -j4
```

# example code

```cpp
// main.cpp

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

```

Run result.
```
[ "Hello", ",", "World", "!", "This", "is", "a", "Hello", "World", "program" ]
[ 1, 2, 3, 4, 5, 6, 7, 8 ]
1, 2, 3, 4, 5, 6, 7, 8
[ ".", "..", "example.cbp", "CMakeFiles", "Makefile", "example", "cmake_install.cmake" ]
```
