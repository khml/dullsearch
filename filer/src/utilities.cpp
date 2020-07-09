//
// Created by KHML on 2020/07/09.
//

#include <sys/stat.h>

#include <tinylexer/filer/utilities.hpp>

namespace tinylex
{
    bool isDir(const std::string& path)
    {
        struct ::stat st;
        stat(path.c_str(), &st);
        bool result = ((st.st_mode & S_IFMT) == S_IFDIR);
        return result;
    }
}