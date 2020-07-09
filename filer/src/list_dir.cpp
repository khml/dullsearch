//
// Created by KHML on 2020/07/09.
//

#include <dirent.h>
#include <utility>

#include <tinylexer/filer/list_dir.hpp>

namespace tinylex
{
    std::vector<std::string> listDir(const std::string& path)
    {
        std::vector<std::string> files;
        DIR* dirPtr = opendir(path.c_str());
        if(dirPtr == NULL)
        {
            ::closedir(dirPtr);
            return std::move(files);
        }

        struct ::dirent* entry = NULL;
        entry = ::readdir(dirPtr);
        while (entry != NULL)
        {
            files.emplace_back(std::string(entry->d_name));
            entry = ::readdir(dirPtr);
        }
        closedir(dirPtr);
        return std::move(files);
    }
}