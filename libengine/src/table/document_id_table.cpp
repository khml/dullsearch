//
// Created by KHML on 2020/07/11.
//

#include <stdexcept>
#include <sstream>

#include <tinylexer/table/document_id_table.hpp>
#include <tinylexer/filer/file.hpp>
#include <tinylexer/lexer/lexer.hpp>

namespace tinylex
{
    DocumentIdTable::DocumentIdTable()
    = default;

    DocumentIdTable::~DocumentIdTable()
    = default;

    void DocumentIdTable::setIds(const std::string& filepath)
    {
        if (docTable.contain(filepath))
            return;

        const size_t docId = docTable.getId(filepath);
        const std::vector<std::string> words = lex(readFileToStr(filepath));
        const std::vector<size_t> wordIds = wordTable.getIds(words);
        for (const size_t& wordId: wordIds)
            relationTable[wordId].emplace(docId);
    }

    std::vector<std::string> DocumentIdTable::lookupFiles(const std::string& word)
    {
        std::vector<std::string> files;
        if (!wordTable.contain(word))
            return files;

        const size_t wordId = wordTable.getId(word);
        const std::unordered_set<size_t> docIds = relationTable[wordId];
        for (const size_t& docId:docIds)
            files.emplace_back(docTable.getValue(docId));
        return files;
    }

    void DocumentIdTable::dump(const std::string& filepath) const
    {
        std::vector<std::string> lines;
        lines.reserve(wordTable.size() + docTable.size() + relationTable.size());

        for (const std::string& word : wordTable.values())
            lines.emplace_back(word);
        lines.emplace_back("");

        for (const std::string& doc : docTable.values())
            lines.emplace_back(doc);
        lines.emplace_back("");

        std::ostringstream oss;
        for (size_t idx = 1; idx < relationTable.size(); idx++)
        {
            oss.str("");
            const std::unordered_set<size_t>& docIds = relationTable.at(idx);
            for (auto iter = docIds.begin(); iter != docIds.end();)
            {
                oss << *iter;
                if (++iter != docIds.end())
                    oss << ",";
            }
            lines.emplace_back(oss.str());
        }

        writeLinesToFile(filepath, lines);
    }
}