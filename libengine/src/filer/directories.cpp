//
// Created by KHML on 2020/07/09.
//

#include <dirent.h>
#include <filesystem>

#include <dullsearch/filer/directories.hpp>
#include <dullsearch/filer/utilities.hpp>

namespace fs = std::filesystem;

namespace dullsearch
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

    std::vector<std::string> listDirRecursive(const std::string& path)
    {
        std::vector<std::string> pathList;
        fs::file_status status = fs::status(path);
        if (!fs::exists(status) || status.type() != fs::file_type::directory)
            return pathList;

        for(const fs::directory_entry& entry: fs::recursive_directory_iterator(path))
            pathList.emplace_back(entry.path().string());

        return pathList;
    }
}