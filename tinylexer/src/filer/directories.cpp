//
// Created by KHML on 2020/07/09.
//

#include <dirent.h>

#include <tinylexer/filer/directories.hpp>
#include <tinylexer/filer/utilities.hpp>

namespace tinylex
{
    std::vector<std::string> listDir(const std::string& path)
    {
        std::vector<std::string> files;

        if (isDir(path))
            return files;

        DIR* dirPtr = opendir(path.c_str());
        if (dirPtr == nullptr)
        {
            ::closedir(dirPtr);
            return files;
        }

        struct ::dirent* entry = nullptr;
        entry = ::readdir(dirPtr);
        while (entry != nullptr)
        {
            files.emplace_back(std::string(entry->d_name));
            entry = ::readdir(dirPtr);
        }
        closedir(dirPtr);
        return files;
    }
}