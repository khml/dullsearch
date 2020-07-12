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

        explicit WordIdTable(const std::vector<std::string>& words);

        virtual ~WordIdTable();

        size_t getId(const std::string& word);

        std::vector<size_t> getIds(const std::vector<std::string>& words);

        std::vector<size_t> getIdsWithUniqSort(const std::vector<std::string>& words);

        std::unordered_map<std::string, size_t> unwrap();

        void dump(const std::string& filepath);

        void restore(const std::string& filepath);

        void print();

        void clear();

    private:
        static const size_t NON_EXIST_ID = 0;
        struct WordId
        {
            size_t id = NON_EXIST_ID;
        };

        size_t id_counter{1};

        std::unordered_map<std::string, WordId> hashmap;

        inline bool exist(const std::string& word);

        void set_id(const std::string& word);
    };
}

#endif //TINYLEXER_TABLE_TABLE_HPP
