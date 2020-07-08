# tinylexer

example code

```cpp
// main.cpp

#include <tinylexer/lexer.hpp>
#include <wordid/table.hpp>

int main()
{
    // a string line to a vector of string
    std::vector<std::string> words = tinylex::toWords("Hello, World! This is a Hello World program");
    tinylex::printWords(words); // show result

    wordid::WordIdTable table; // create word id table
    auto ids = table.get_ids(words); // get ids from words
    table.print();  // show table
    wordid::printIds(ids);
    wordid::uniqSort(ids);
    wordid::printIds(ids);

    return 0;
}

```

Run result.
```
[ "Hello", ",", "World", "!", "This", "is", "a", "Hello", "World", "program" ]
{ "program": 8, "is": 6, "This": 5, "World": 3, ",": 2, "!": 4, "a": 7, "Hello": 1 }
[ 1, 2, 3, 4, 5, 6, 7, 1, 3, 8 ]
[ 1, 2, 3, 4, 5, 6, 7, 8 ]
```
