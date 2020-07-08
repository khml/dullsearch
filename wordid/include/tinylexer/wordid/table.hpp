//
// Created by KHML on 2020/07/07.
//

#ifndef TINYLEXER_TABLE_HPP
#define TINYLEXER_TABLE_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include <tinylexer/wordid/utilities.hpp>

namespace wordid
{
    class WordIdTable
    {
    public:
        WordIdTable();

        explicit WordIdTable(const std::vector<std::string>& words);

        virtual ~WordIdTable();

        size_t get_id(const std::string& word);

        std::vector<size_t> get_ids(const std::vector<std::string>& words);

        std::unordered_map<std::string, size_t> unwrap();

        void print();

    private:
        static const size_t NON_EXIST_ID = 0;
        struct WordId
        {
            size_t id = NON_EXIST_ID;
        };

        size_t id_counter;

        std::unordered_map<std::string, WordId> hashmap;

        inline bool exist(const  std::string& word);

        void set_id(const std::string& word);
    };

    void printIds(const std::vector<size_t>& ids);
}

#endif //TINYLEXER_TABLE_HPP
