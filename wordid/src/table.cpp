//
// Created by KHML on 2020/07/07.
//

#include <iostream>
#include <utility>

#include <tinylexer/wordid/table.hpp>

namespace wordid
{
    WordIdTable::WordIdTable()
    {}

    WordIdTable::~WordIdTable()
    = default;

    WordIdTable::WordIdTable(const std::vector<std::string>& words)
    {
        hashmap.reserve(words.size());
        for (const auto& word : words)
            set_id(word);
    }

    size_t WordIdTable::get_id(const std::string& word)
    {
        if (exist(word))
            return hashmap[word].id;

        hashmap[word].id = id_counter++;
        return hashmap[word].id;
    }

    std::vector<size_t> WordIdTable::get_ids(const std::vector<std::string>& words)
    {
        std::vector<size_t> ids;
        ids.reserve(words.size());
        for (const std::string& word : words)
            ids.emplace_back(get_id(word));
        return std::move(ids);
    }

    std::unordered_map<std::string, size_t> WordIdTable::unwrap()
    {
        std::unordered_map<std::string, size_t> container;
        container.reserve(hashmap.size());
        for (auto& item : hashmap)
            container[item.first] = item.second.id;
        return std::move(container);
    }

    void WordIdTable::print()
    {
        std::cout << "{ ";
        size_t size = hashmap.size();
        size_t i = 0;
        for (auto& item: hashmap)
        {
            std::cout << '"' << item.first << '"' << ": " << item.second.id;
            if (++i < size)
                std::cout << ", ";
        }
        std::cout << " }" << std::endl;
    }

    inline bool WordIdTable::exist(const std::string& word)
    {
        return (hashmap[word].id > NON_EXIST_ID);
    }

    void WordIdTable::set_id(const std::string& word)
    {
        if (exist(word))
            return;
        hashmap[word] = WordId{id_counter++};
    }
}
