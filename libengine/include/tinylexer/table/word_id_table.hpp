//
// Created by KHML on 2020/07/07.
//

#ifndef TINYLEXER_TABLE_TABLE_HPP
#define TINYLEXER_TABLE_TABLE_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include <tinylexer/table/utilities.hpp>

namespace tinylex
{
    class WordIdTable
    {
    public:
        WordIdTable();

        explicit WordIdTable(const std::string& filepath);

        virtual ~WordIdTable();

        size_t getId(const std::string& word);

        std::string getValue(const size_t& wordId);

        std::vector<size_t> getIds(const std::vector<std::string>& words);

        std::vector<size_t> getIdsWithUniqSort(const std::vector<std::string>& words);

        bool contain(const std::string& word);

        std::unordered_map<std::string, size_t> unwrap() const;

        std::vector<std::string> values() const;

        size_t size() const;

        void dump(const std::string& filepath) const;

        void restore(const std::string& filepath);

        void print() const;

        void clear();

    private:
        static const size_t NON_EXIST_ID = 0;
        size_t id_counter{1};
        struct WordId
        {
            size_t id = NON_EXIST_ID;
        };
        std::unordered_map<std::string, WordId> table;
        std::unordered_map<size_t, std::string> revTable;

        void set_id(const std::string& word);

        inline size_t emitId();
    };
}

#endif //TINYLEXER_TABLE_TABLE_HPP
