//
// Created by KHML on 2020/07/07.
//

#include <iostream>
#include <utility>

#include <wordid/container.hpp>

namespace wordid
{
    Container::Container() :id_counter(1)
    {}

    Container::~Container()
    = default;

    Container::Container(const std::vector<std::string>& words) :Container()
    {
        for (const auto& word : words)
            set_id(word);
    }

    size_t Container::get_id(const std::string& word)
    {
        if (exist(word))
            return hashmap[word].id;

        hashmap[word].id = id_counter++;
        return hashmap[word].id;
    }

    std::unordered_map<std::string, size_t> Container::unwrap()
    {
        std::unordered_map<std::string, size_t> container;
        for (auto& item : hashmap)
            container[item.first] = item.second.id;
        return std::move(container);
    }

    void Container::print()
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

    inline bool Container::exist(const std::string& word)
    {
        return (hashmap[word].id > NON_EXIST_ID);
    }

    void Container::set_id(const std::string& word)
    {
        if (exist(word))
            return;
        hashmap[word] = WordId{id_counter++};
    }
}
