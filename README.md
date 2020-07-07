# tinylexer

example code

```cpp
// main.cpp

#include <tinylexer/lexer.hpp>

int main()
{
    auto words = tinylex::toWords("Hello, World!");
    tinylex::printWords(words);
    return 0;
}

```

Run result.
```
[ "Hello", ",", "World", "!" ]
```
