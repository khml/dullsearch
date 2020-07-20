// example.cpp

#include <iostream>
#include <string>
#include <vector>

#include <tinylexer.hpp>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "need an argument: dir path" << std::endl;
        return 0;
    }
    const std::string pathname = argv[1];

    const std::vector<std::string> filenames = tinylex::listDirRecursive(pathname);
    for(const std::string& filename:filenames)
        std::cout << filename << std::endl;

    return 0;
}
