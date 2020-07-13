//
// Created by KHML on 2020/07/07.
//

#include <iostream>
#include <stdexcept>
#include <utility>

#include <tinylexer/table/word_id_table.hpp>
#include <tinylexer/filer/file.hpp>

namespace tinylex
{
    WordIdTable::WordIdTable()
    = default;

    WordIdTable::WordIdTable(const std::string& filepath)
    {
        restore(filepath);
    }

    WordIdTable::~WordIdTable()
    = default;

    size_t WordIdTable::getId(const std::string& word)
    {
        set_id(word);
        return table[word].id;
    }

    std::string WordIdTable::getValue(const size_t& wordId)
    {
        if (wordId >= id_counter)
            throw std::runtime_error("NOT FOUND. wordId=" + std::to_string(wordId));
        return revTable[wordId];
    }

    std::vector<size_t> WordIdTable::getIds(const std::vector<std::string>& words)
    {
        std::vector<size_t> ids;
        ids.reserve(words.size());
        for (const std::string& word : words)
            ids.emplace_back(getId(word));
        return ids;
    }

    std::vector<size_t> WordIdTable::getIdsWithUniqSort(const std::vector<std::string>& words)
    {
        auto ids = getIds(words);
        uniqSort(ids);
        return ids;
    }

    bool WordIdTable::contain(const std::string& word)
    {
        return (table[word].id != NON_EXIST_ID);
    }

    std::unordered_map<std::string, size_t> WordIdTable::unwrap() const
    {
        std::unordered_map<std::string, size_t> container;
        container.reserve(table.size());
        for (const auto& item : table)
            container[item.first] = item.second.id;
        return container;
    }

    void WordIdTable::dump(const std::string& filepath) const
    {
        std::vector<std::string> lines;
        lines.resize(table.size());
        constexpr size_t adjuster = NON_EXIST_ID + 1;
        for (const auto& item : table)
        {
            lines[item.second.id - adjuster] = item.first;
        }
        writeLinesToFile(filepath, lines);
    }

    void WordIdTable::restore(const std::string& filepath)
    {
        const std::vector<std::string> lines = readFile(filepath);
        clear();
        for (const std::string& line:lines)
            set_id(line);
    }

    void WordIdTable::print() const
    {
        std::cout << "{ ";
        size_t size = table.size();
        size_t i = 0;
        for (auto& item: table)
        {
            std::cout << '"' << item.first << '"' << ": " << item.second.id;
            if (++i < size)
                std::cout << ", ";
        }
        std::cout << " }" << std::endl;
    }

    void WordIdTable::clear()
    {
        id_counter = NON_EXIST_ID + 1;
        table.clear();
    }

    void WordIdTable::set_id(const std::string& word)
    {
        if (contain(word))
            return;
        table[word] = WordId{emitId()};
        revTable[table[word].id] = word;
    }

    inline size_t WordIdTable::emitId()
    {
        return id_counter++;
    }
}
