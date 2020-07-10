//
// Created by KHML on 2020/07/09.
//

#include <sys/stat.h>

#include <tinylexer/filer/utilities.hpp>

namespace tinylex
{
    mode_t getMode(const std::string& path)
    {
        struct ::stat st{};
        stat(path.c_str(), &st);
        return (st.st_mode & S_IFMT);
    }

    bool isDir(const std::string& path)
    {
        return (getMode(path) == S_IFDIR);
    }

    bool isReg(const std::string& path)
    {
        return (getMode(path) == S_IFREG);
    }
}