//
// Created by KHML on 2020/07/07.
//

#ifndef TINYLEXER_WORDID_TABLE_HPP
#define TINYLEXER_WORDID_TABLE_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include <tinylexer/wordid/utilities.hpp>

namespace tinylex
{
    class WordIdTable
    {
    public:
        WordIdTable();

        explicit WordIdTable(const std::vector<std::string>& words);

        virtual ~WordIdTable();

        size_t get_id(const std::string& word);

        std::vector<size_t> get_ids(const std::vector<std::string>& words);

        std::vector<size_t> get_ids_with_uniq_sort(const std::vector<std::string>& words);

        std::unordered_map<std::string, size_t> unwrap();

        void print();

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

#endif //TINYLEXER_WORDID_TABLE_HPP