//
// Created by KHML on 2020/07/07.
//

#ifndef TINYLEXER_CONTAINER_HPP
#define TINYLEXER_CONTAINER_HPP

#include <string>
#include <unordered_map>
#include <vector>

namespace wordid
{
    class Container
    {
    public:
        Container();

        explicit Container(const std::vector<std::string>& words);

        virtual ~Container();

        size_t get_id(const std::string& word);

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
}

#endif //TINYLEXER_CONTAINER_HPP
