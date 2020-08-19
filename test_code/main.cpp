//
// Created by KHML on 2020/07/09.
//

#include <fstream>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <dullsearch.hpp>
#include <dullsearch/lexer/symbol.hpp>

TEST(TestLexer, lex)
{
    EXPECT_THAT(dullsearch::lex("Hello World!"),
        testing::ElementsAre("Hello", "World", "!"));

    EXPECT_THAT(dullsearch::lex("1+2*3/6"),
        testing::ElementsAre("1", "+", "2", "*", "3", "/", "6"));

    EXPECT_THAT(dullsearch::lex(
        "class HelloWorld { public static void main(String[] args) { System.out.println(\"Hello, world.\"); } }"),
        testing::ElementsAre("class", "HelloWorld", "{", "public", "static", "void", "main", "(", "String", "[", "]",
            "args", ")", "{", "System", ".", "out", ".", "println", "(", "Hello", "world", ".", ")", ";", "}", "}"));
}

TEST(TestSymbol, toSymbol)
{
    EXPECT_EQ(dullsearch::symbol::toSymbol("+"), dullsearch::symbol::ADD);
    EXPECT_EQ(dullsearch::symbol::toSymbol("-"), dullsearch::symbol::SUB);
    EXPECT_EQ(dullsearch::symbol::toSymbol("*"), dullsearch::symbol::ASTERISK);
    EXPECT_EQ(dullsearch::symbol::toSymbol("/"), dullsearch::symbol::SLASH);
    EXPECT_EQ(dullsearch::symbol::toSymbol("@"), dullsearch::symbol::AT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("="), dullsearch::symbol::EQUAL);
    EXPECT_EQ(dullsearch::symbol::toSymbol(")"), dullsearch::symbol::PARENTHESISE_RIGHT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("("), dullsearch::symbol::PARENTHESIS_LEFT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("]"), dullsearch::symbol::BRACKET_RIGHT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("["), dullsearch::symbol::BRACKET_LEFT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("}"), dullsearch::symbol::BRACE_RIGHT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("{"), dullsearch::symbol::BRACE_LEFT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("."), dullsearch::symbol::DOT);
    EXPECT_EQ(dullsearch::symbol::toSymbol(","), dullsearch::symbol::COMMA);
    EXPECT_EQ(dullsearch::symbol::toSymbol(":"), dullsearch::symbol::COLON);
    EXPECT_EQ(dullsearch::symbol::toSymbol(";"), dullsearch::symbol::SEMICOLON);
    EXPECT_EQ(dullsearch::symbol::toSymbol("?"), dullsearch::symbol::INTERROGATION);
    EXPECT_EQ(dullsearch::symbol::toSymbol(">"), dullsearch::symbol::GRATER_THAN);
    EXPECT_EQ(dullsearch::symbol::toSymbol("<"), dullsearch::symbol::LESSER_THAN);
    EXPECT_EQ(dullsearch::symbol::toSymbol("\'"), dullsearch::symbol::APOSTROPHE);
    EXPECT_EQ(dullsearch::symbol::toSymbol("\""), dullsearch::symbol::QUOTATION);
    EXPECT_EQ(dullsearch::symbol::toSymbol("&"), dullsearch::symbol::AMPERSAND);
    EXPECT_EQ(dullsearch::symbol::toSymbol("%"), dullsearch::symbol::PERCENT);
    EXPECT_EQ(dullsearch::symbol::toSymbol("$"), dullsearch::symbol::DOLLAR);
    EXPECT_EQ(dullsearch::symbol::toSymbol("#"), dullsearch::symbol::SHARP);
    EXPECT_EQ(dullsearch::symbol::toSymbol("|"), dullsearch::symbol::PIPE);
    EXPECT_EQ(dullsearch::symbol::toSymbol("_"), dullsearch::symbol::UNDER_BAR);
    EXPECT_EQ(dullsearch::symbol::toSymbol("\\"), dullsearch::symbol::BACKSLASH);
    EXPECT_EQ(dullsearch::symbol::toSymbol(" "), dullsearch::symbol::WHITESPACE);
    EXPECT_EQ(dullsearch::symbol::toSymbol("\n"), dullsearch::symbol::NEW_LINE);
    EXPECT_EQ(dullsearch::symbol::toSymbol("=="), dullsearch::symbol::EQUIVALENCE);
    EXPECT_EQ(dullsearch::symbol::toSymbol(">="), dullsearch::symbol::GRATER);
    EXPECT_EQ(dullsearch::symbol::toSymbol("<="), dullsearch::symbol::LESSER);
    EXPECT_EQ(dullsearch::symbol::toSymbol("++"), dullsearch::symbol::INCREMENTAL);
    EXPECT_EQ(dullsearch::symbol::toSymbol("--"), dullsearch::symbol::DECREMENTAL);
    EXPECT_EQ(dullsearch::symbol::toSymbol("&&"), dullsearch::symbol::AND);
    EXPECT_EQ(dullsearch::symbol::toSymbol("||"), dullsearch::symbol::OR);
    EXPECT_EQ(dullsearch::symbol::toSymbol("/*"), dullsearch::symbol::COMMENT_START);
    EXPECT_EQ(dullsearch::symbol::toSymbol("*/"), dullsearch::symbol::COMMENT_END);
    EXPECT_EQ(dullsearch::symbol::toSymbol("->"), dullsearch::symbol::ARROW);
    EXPECT_EQ(dullsearch::symbol::toSymbol("=>"), dullsearch::symbol::FAT_ARROW);
    EXPECT_EQ(dullsearch::symbol::toSymbol("!"), dullsearch::symbol::EXCLAMATION);
    EXPECT_EQ(dullsearch::symbol::toSymbol("a"), dullsearch::symbol::IDENTIFIER);
    EXPECT_EQ(dullsearch::symbol::toSymbol("0"), dullsearch::symbol::IDENTIFIER);
}

TEST(TestUtilities, isDigit)
{
    for (int i = 0; i < 20; i++)
        EXPECT_TRUE(dullsearch::isDigit(std::to_string(i)));

    EXPECT_FALSE(dullsearch::isDigit("a"));
    EXPECT_FALSE(dullsearch::isDigit("1.1"));
}

TEST(TestUtilities, isFloat)
{
    EXPECT_TRUE(dullsearch::isFloat("1.1f"));
    EXPECT_TRUE(dullsearch::isFloat(".11f"));

    EXPECT_FALSE(dullsearch::isFloat("10f"));
    EXPECT_FALSE(dullsearch::isFloat("1.1.1f"));
    EXPECT_FALSE(dullsearch::isFloat("1.1"));
    EXPECT_FALSE(dullsearch::isFloat("f"));
    EXPECT_FALSE(dullsearch::isFloat("a"));
}

TEST(TestUtilities, isDouble)
{
    EXPECT_TRUE(dullsearch::isDouble("1.1"));
    EXPECT_TRUE(dullsearch::isDouble("10.1"));
    EXPECT_TRUE(dullsearch::isDouble("1.01"));
    EXPECT_TRUE(dullsearch::isDouble(".100"));

    EXPECT_FALSE(dullsearch::isDouble("100"));
    EXPECT_FALSE(dullsearch::isDouble("a"));
}

TEST(TestUtilities, isIdentifier)
{
    EXPECT_TRUE(dullsearch::isIdentifier("hello"));
    EXPECT_TRUE(dullsearch::isIdentifier("_hello"));
    EXPECT_TRUE(dullsearch::isIdentifier("hello_"));
    EXPECT_TRUE(dullsearch::isIdentifier("Hello"));
    EXPECT_TRUE(dullsearch::isIdentifier("WORLD"));
    EXPECT_TRUE(dullsearch::isIdentifier("a100"));
}

TEST(TestUtilities, splitByComma)
{
    EXPECT_THAT(dullsearch::splitByComma("1,2,3,4,5"),
        testing::ElementsAre("1", "2", "3", "4", "5"));

    EXPECT_THAT(dullsearch::splitByComma("1, \"2\", ',3', a'4', 5"),
        testing::ElementsAre("1", "2", ",3", "a'4'", "5"));

    EXPECT_THAT(dullsearch::splitByComma("1"),
        testing::ElementsAre("1"));

    EXPECT_THAT(dullsearch::splitByComma("1,"),
        testing::ElementsAre("1"));
}

TEST(TestUtilities, uniqSort)
{
    std::vector<size_t> source = {100, 1, 20, 2, 5, 100};
    dullsearch::uniqSort(source);
    EXPECT_THAT(source, testing::ElementsAre(1, 2, 5, 20, 100));
}

TEST(TestUtilities, toStr)
{
    std::vector<size_t> source = {100, 1, 20, 2, 5};
    EXPECT_EQ(dullsearch::toStr(source), "100, 1, 20, 2, 5");
}

TEST(TestUtilities, isDir)
{
    EXPECT_TRUE(dullsearch::isDir("."));
    EXPECT_TRUE(dullsearch::isDir(".."));

    const std::string filepath("TestUtilities_isDir_dummy.txt");
    std::ofstream file(filepath);
    file.flush();
    EXPECT_FALSE(dullsearch::isDir(filepath));
}

TEST(TestReadCsv, readCsvFile)
{
    const std::string filepath("TestReadCsv_readCsvFile_dummy.csv");
    std::ofstream file(filepath);
    file << "0,1,2,3,4" << std::endl;
    file.flush();
    EXPECT_EQ(dullsearch::readCsvFile(filepath).size(), (size_t) 1);
    EXPECT_THAT(dullsearch::readCsvFile(filepath)[0], testing::ElementsAre("0", "1", "2", "3", "4"));

    file << "5, 6,  7" << std::endl;
    file.flush();
    EXPECT_EQ(dullsearch::readCsvFile(filepath).size(), (size_t) 2);
    EXPECT_THAT(dullsearch::readCsvFile(filepath)[1], testing::ElementsAre("5", "6", "7"));
}

TEST(TestWordIdTable, getId)
{
    dullsearch::WordIdTable table;
    EXPECT_EQ(table.getId("Hello"), (size_t) 1);
    EXPECT_EQ(table.getId("Hello"), (size_t) 1);

    EXPECT_EQ(table.getId("World"), (size_t) 2);
    EXPECT_EQ(table.getId("Hello"), (size_t) 1);
}

TEST(TestWordIdTable, getIds)
{
    dullsearch::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids = table.getIds(words);
    EXPECT_THAT(ids, testing::ElementsAre(1, 2, 3, 4, 5, 1, 2, 6, 3));

    ids = table.getIds(words);
    EXPECT_THAT(ids, testing::ElementsAre(1, 2, 3, 4, 5, 1, 2, 6, 3));

    words = {"This", "Is", "Test", "Code", "."};
    ids = table.getIds(words);
    EXPECT_THAT(ids, testing::ElementsAre(4, 5, 7, 6, 3));
}

TEST(TestWordIdTable, getIdsWithUniqSort)
{
    dullsearch::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids_sorted = table.getIdsWithUniqSort(words);

    std::vector<std::size_t> ids = table.getIds(words);
    dullsearch::uniqSort(ids);
    EXPECT_THAT(ids_sorted, ids);
}

TEST(TestWordIdTable, contain)
{
    dullsearch::WordIdTable table;
    const std::string key = "Hello";
    EXPECT_FALSE(table.contain(key));
    EXPECT_FALSE(table.contain(key));

    table.getId(key);
    EXPECT_TRUE(table.contain(key));
}

TEST(TestWordIdTable, getValue)
{
    dullsearch::WordIdTable table;
    const std::string key = "Hello";
    const size_t id = table.getId(key);
    EXPECT_EQ(table.getValue(id), key);
}

TEST(TestWordIdTable, unwrap)
{
    dullsearch::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids = table.getIds(words);
    std::unordered_map<std::string, size_t> unwrapTable = table.unwrap();

    EXPECT_EQ(unwrapTable.size(), (size_t) 6);

    for (size_t idx = 0; idx < words.size(); idx++)
    {
        EXPECT_EQ(unwrapTable[words[idx]], ids[idx]);
    }
}

TEST(TestWordIdTable, values)
{
    dullsearch::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    (void) table.getIds(words);
    std::vector<std::string> values = table.values();

    EXPECT_EQ(values.size(), (size_t) 6);
    EXPECT_THAT(values, testing::Pointwise(testing::Eq(), {"Hello", "World", ".", "This", "Is", "Code"}));
}

TEST(TestWordIdTable, size)
{
    dullsearch::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    (void) table.getIds(words);

    EXPECT_EQ(table.size(), (size_t) 6);
}

TEST(TestWordIdTable, dump)
{
    const std::string filename = "TestWordIdTable_dump.dullsearch";
    dullsearch::WordIdTable table;
    const std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    const std::vector<size_t> ids = table.getIds(words);
    table.dump(filename);

    std::ifstream file(filename);
    ASSERT_FALSE(file.fail());
    std::string line;
    std::vector<std::string> lines;
    while (getline(file, line))
        lines.emplace_back(line);

    for (size_t idx = 0; idx < ids.size(); idx++)
        EXPECT_EQ(lines[ids[idx] - 1], words[idx]);
}

TEST(TestWordIdTable, restore)
{
    const std::string filename = "TestWordIdTable_restore.dullsearch";
    const std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    dullsearch::WordIdTable tableA;
    const std::vector<size_t> ids = tableA.getIds(words);

    std::ofstream file(filename);
    ASSERT_FALSE(file.fail());
    for (const std::string& word:words)
        file << word << std::endl;
    file.flush();

    dullsearch::WordIdTable tableB;
    tableB.restore(filename);
    EXPECT_THAT(tableB.getIds(words), testing::Pointwise(testing::Eq(), ids));
}

TEST(TestWordIdTable, clear)
{
    dullsearch::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids = table.getIds(words);
    std::unordered_map<std::string, size_t> unwrapTable = table.unwrap();

    EXPECT_EQ(unwrapTable.size(), (size_t) 6);

    table.clear();
    unwrapTable = table.unwrap();
    EXPECT_EQ(unwrapTable.size(), (size_t) 0);

    EXPECT_EQ(table.getId("hello"), (size_t) 1);
    EXPECT_EQ(table.getId("world"), (size_t) 2);
    table.clear();
    EXPECT_EQ(table.getId("world"), (size_t) 1);
}

TEST(TestDocumentIdTable, lookupFiles)
{
    const std::string filepathA = "TestDocumentIdTable_lookupFiles_a.txt";
    const std::string filepathB = "TestDocumentIdTable_lookupFiles_b.txt";
    const std::string filepathC = "TestDocumentIdTable_lookupFiles_c.txt";
    std::ofstream fileA(filepathA);
    std::ofstream fileB(filepathB);
    std::ofstream fileC(filepathC);
    fileA << "Hello World" << std::endl;
    fileB << "This Is" << std::endl;
    fileC << "Hello World program" << std::endl;
    fileA.flush();
    fileB.flush();
    fileC.flush();

    dullsearch::DocumentTable table;
    table.setIds(filepathA);
    table.setIds(filepathB);

    EXPECT_THAT(table.lookupFiles("Hello"), testing::Contains(filepathA));
    EXPECT_THAT(table.lookupFiles("This"), testing::Not(testing::Contains(filepathA)));
    EXPECT_THAT(table.lookupFiles("This"), testing::Contains(filepathB));

    table.setIds(filepathC);
    EXPECT_THAT(table.lookupFiles("Hello"),
        testing::UnorderedElementsAre(testing::Eq(filepathA), testing::Eq(filepathC)));
    EXPECT_THAT(table.lookupFiles("Hello"), testing::Not(testing::Contains(filepathB)));

    EXPECT_THAT(table.lookupFiles("program"), testing::Contains(filepathC));
    EXPECT_THAT(table.lookupFiles("program"),
        testing::Not(testing::UnorderedElementsAre(testing::Eq(filepathA), testing::Eq(filepathB))));
}