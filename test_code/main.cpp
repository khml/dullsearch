//
// Created by KHML on 2020/07/09.
//

#include <fstream>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <tinylexer.hpp>
#include <tinylexer/lexer/symbol.hpp>

TEST(TestLexer, lex)
{
    EXPECT_THAT(tinylex::lex("Hello World!"),
        testing::ElementsAre("Hello", "World", "!"));

    EXPECT_THAT(tinylex::lex("1+2*3/6"),
        testing::ElementsAre("1", "+", "2", "*", "3", "/", "6"));

    EXPECT_THAT(tinylex::lex(
        "class HelloWorld { public static void main(String[] args) { System.out.println(\"Hello, world.\"); } }"),
        testing::ElementsAre("class", "HelloWorld", "{", "public", "static", "void", "main", "(", "String", "[", "]",
            "args", ")", "{", "System", ".", "out", ".", "println", "(", "Hello, world.", ")", ";", "}", "}"));
}

TEST(TestSymbol, toSymbol)
{
    EXPECT_EQ(tinylex::symbol::toSymbol("+"), tinylex::symbol::ADD);
    EXPECT_EQ(tinylex::symbol::toSymbol("-"), tinylex::symbol::SUB);
    EXPECT_EQ(tinylex::symbol::toSymbol("*"), tinylex::symbol::ASTERISK);
    EXPECT_EQ(tinylex::symbol::toSymbol("/"), tinylex::symbol::SLASH);
    EXPECT_EQ(tinylex::symbol::toSymbol("@"), tinylex::symbol::AT);
    EXPECT_EQ(tinylex::symbol::toSymbol("="), tinylex::symbol::EQUAL);
    EXPECT_EQ(tinylex::symbol::toSymbol(")"), tinylex::symbol::PARENTHESISE_RIGHT);
    EXPECT_EQ(tinylex::symbol::toSymbol("("), tinylex::symbol::PARENTHESIS_LEFT);
    EXPECT_EQ(tinylex::symbol::toSymbol("]"), tinylex::symbol::BRACKET_RIGHT);
    EXPECT_EQ(tinylex::symbol::toSymbol("["), tinylex::symbol::BRACKET_LEFT);
    EXPECT_EQ(tinylex::symbol::toSymbol("}"), tinylex::symbol::BRACE_RIGHT);
    EXPECT_EQ(tinylex::symbol::toSymbol("{"), tinylex::symbol::BRACE_LEFT);
    EXPECT_EQ(tinylex::symbol::toSymbol("."), tinylex::symbol::DOT);
    EXPECT_EQ(tinylex::symbol::toSymbol(","), tinylex::symbol::COMMA);
    EXPECT_EQ(tinylex::symbol::toSymbol(":"), tinylex::symbol::COLON);
    EXPECT_EQ(tinylex::symbol::toSymbol(";"), tinylex::symbol::SEMICOLON);
    EXPECT_EQ(tinylex::symbol::toSymbol("?"), tinylex::symbol::INTERROGATION);
    EXPECT_EQ(tinylex::symbol::toSymbol(">"), tinylex::symbol::GRATER_THAN);
    EXPECT_EQ(tinylex::symbol::toSymbol("<"), tinylex::symbol::LESSER_THAN);
    EXPECT_EQ(tinylex::symbol::toSymbol("\'"), tinylex::symbol::APOSTROPHE);
    EXPECT_EQ(tinylex::symbol::toSymbol("\""), tinylex::symbol::QUOTATION);
    EXPECT_EQ(tinylex::symbol::toSymbol("&"), tinylex::symbol::AMPERSAND);
    EXPECT_EQ(tinylex::symbol::toSymbol("%"), tinylex::symbol::PERCENT);
    EXPECT_EQ(tinylex::symbol::toSymbol("$"), tinylex::symbol::DOLLAR);
    EXPECT_EQ(tinylex::symbol::toSymbol("#"), tinylex::symbol::SHARP);
    EXPECT_EQ(tinylex::symbol::toSymbol("|"), tinylex::symbol::PIPE);
    EXPECT_EQ(tinylex::symbol::toSymbol("_"), tinylex::symbol::UNDER_BAR);
    EXPECT_EQ(tinylex::symbol::toSymbol("\\"), tinylex::symbol::BACKSLASH);
    EXPECT_EQ(tinylex::symbol::toSymbol(" "), tinylex::symbol::WHITESPACE);
    EXPECT_EQ(tinylex::symbol::toSymbol("\n"), tinylex::symbol::NEW_LINE);
    EXPECT_EQ(tinylex::symbol::toSymbol("=="), tinylex::symbol::EQUIVALENCE);
    EXPECT_EQ(tinylex::symbol::toSymbol(">="), tinylex::symbol::GRATER);
    EXPECT_EQ(tinylex::symbol::toSymbol("<="), tinylex::symbol::LESSER);
    EXPECT_EQ(tinylex::symbol::toSymbol("++"), tinylex::symbol::INCREMENTAL);
    EXPECT_EQ(tinylex::symbol::toSymbol("--"), tinylex::symbol::DECREMENTAL);
    EXPECT_EQ(tinylex::symbol::toSymbol("&&"), tinylex::symbol::AND);
    EXPECT_EQ(tinylex::symbol::toSymbol("||"), tinylex::symbol::OR);
    EXPECT_EQ(tinylex::symbol::toSymbol("/*"), tinylex::symbol::COMMENT_START);
    EXPECT_EQ(tinylex::symbol::toSymbol("*/"), tinylex::symbol::COMMENT_END);
    EXPECT_EQ(tinylex::symbol::toSymbol("->"), tinylex::symbol::ARROW);
    EXPECT_EQ(tinylex::symbol::toSymbol("=>"), tinylex::symbol::FAT_ARROW);
    EXPECT_EQ(tinylex::symbol::toSymbol("!"), tinylex::symbol::EXCLAMATION);
    EXPECT_EQ(tinylex::symbol::toSymbol("a"), tinylex::symbol::IDENTIFIER);
    EXPECT_EQ(tinylex::symbol::toSymbol("0"), tinylex::symbol::IDENTIFIER);
}

TEST(TestUtilities, isDigit)
{
    for (int i = 0; i < 20; i++)
        EXPECT_TRUE(tinylex::isDigit(std::to_string(i)));

    EXPECT_FALSE(tinylex::isDigit("a"));
    EXPECT_FALSE(tinylex::isDigit("1.1"));
}

TEST(TestUtilities, isFloat)
{
    EXPECT_TRUE(tinylex::isFloat("1.1f"));
    EXPECT_TRUE(tinylex::isFloat(".11f"));

    EXPECT_FALSE(tinylex::isFloat("10f"));
    EXPECT_FALSE(tinylex::isFloat("1.1.1f"));
    EXPECT_FALSE(tinylex::isFloat("1.1"));
    EXPECT_FALSE(tinylex::isFloat("f"));
    EXPECT_FALSE(tinylex::isFloat("a"));
}

TEST(TestUtilities, isDouble)
{
    EXPECT_TRUE(tinylex::isDouble("1.1"));
    EXPECT_TRUE(tinylex::isDouble("10.1"));
    EXPECT_TRUE(tinylex::isDouble("1.01"));
    EXPECT_TRUE(tinylex::isDouble(".100"));

    EXPECT_FALSE(tinylex::isDouble("100"));
    EXPECT_FALSE(tinylex::isDouble("a"));
}

TEST(TestUtilities, isIdentifier)
{
    EXPECT_TRUE(tinylex::isIdentifier("hello"));
    EXPECT_TRUE(tinylex::isIdentifier("_hello"));
    EXPECT_TRUE(tinylex::isIdentifier("hello_"));
    EXPECT_TRUE(tinylex::isIdentifier("Hello"));
    EXPECT_TRUE(tinylex::isIdentifier("WORLD"));
    EXPECT_TRUE(tinylex::isIdentifier("a100"));
}

TEST(TestUtilities, splitByComma)
{
    EXPECT_THAT(tinylex::splitByComma("1,2,3,4,5"),
        testing::ElementsAre("1", "2", "3", "4", "5"));

    EXPECT_THAT(tinylex::splitByComma("1, \"2\", ',3', a'4', 5"),
        testing::ElementsAre("1", "2", ",3", "a'4'", "5"));

    EXPECT_THAT(tinylex::splitByComma("1"),
        testing::ElementsAre("1"));

    EXPECT_THAT(tinylex::splitByComma("1,"),
        testing::ElementsAre("1"));
}

TEST(TestUtilities, uniqSort)
{
    std::vector<size_t> source = {100, 1, 20, 2, 5, 100};
    tinylex::uniqSort(source);
    EXPECT_THAT(source, testing::ElementsAre(1, 2, 5, 20, 100));
}

TEST(TestUtilities, toStr)
{
    std::vector<size_t> source = {100, 1, 20, 2, 5};
    EXPECT_EQ(tinylex::toStr(source), "100, 1, 20, 2, 5");
}

TEST(TestUtilities, isDir)
{
    EXPECT_TRUE(tinylex::isDir("."));
    EXPECT_TRUE(tinylex::isDir(".."));

    const std::string filepath("TestUtilities_isDir_dummy.txt");
    std::ofstream file(filepath);
    file.flush();
    EXPECT_FALSE(tinylex::isDir(filepath));
}

TEST(TestReadCsv, readCsvFile)
{
    const std::string filepath("TestReadCsv_readCsvFile_dummy.csv");
    std::ofstream file(filepath);
    file << "0,1,2,3,4" << std::endl;
    file.flush();
    EXPECT_EQ(tinylex::readCsvFile(filepath).size(), (size_t) 1);
    EXPECT_THAT(tinylex::readCsvFile(filepath)[0], testing::ElementsAre("0", "1", "2", "3", "4"));

    file << "5, 6,  7" << std::endl;
    file.flush();
    EXPECT_EQ(tinylex::readCsvFile(filepath).size(), (size_t) 2);
    EXPECT_THAT(tinylex::readCsvFile(filepath)[1], testing::ElementsAre("5", "6", "7"));
}

TEST(TestWordIdTable, getId)
{
    tinylex::WordIdTable table;
    EXPECT_EQ(table.getId("Hello"), (size_t) 1);
    EXPECT_EQ(table.getId("Hello"), (size_t) 1);

    EXPECT_EQ(table.getId("World"), (size_t) 2);
    EXPECT_EQ(table.getId("Hello"), (size_t) 1);
}

TEST(TestWordIdTable, getIds)
{
    tinylex::WordIdTable table;
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
    tinylex::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids_sorted = table.getIdsWithUniqSort(words);

    std::vector<std::size_t> ids = table.getIds(words);
    tinylex::uniqSort(ids);
    EXPECT_THAT(ids_sorted, ids);
}

TEST(TestWordIdTable, contain)
{
    tinylex::WordIdTable table;
    const std::string key = "Hello";
    EXPECT_FALSE(table.contain(key));
    EXPECT_FALSE(table.contain(key));

    table.getId(key);
    EXPECT_TRUE(table.contain(key));
}

TEST(TestWordIdTable, getValue)
{
    tinylex::WordIdTable table;
    const std::string key = "Hello";
    const size_t id = table.getId(key);
    EXPECT_EQ(table.getValue(id), key);
}

TEST(TestWordIdTable, unwrap)
{
    tinylex::WordIdTable table;
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
    tinylex::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    (void)table.getIds(words);
    std::vector<std::string> values = table.values();

    EXPECT_EQ(values.size(), (size_t) 6);
    EXPECT_THAT(values, testing::Pointwise(testing::Eq(), { "Hello", "World", ".", "This", "Is", "Code" }));
}

TEST(TestWordIdTable, size)
{
    tinylex::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    (void)table.getIds(words);

    EXPECT_EQ(table.size(), (size_t) 6);
}

TEST(TestWordIdTable, dump)
{
    const std::string filename = "TestWordIdTable_dump.tinylex";
    tinylex::WordIdTable table;
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
    const std::string filename = "TestWordIdTable_restore.tinylex";
    const std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    tinylex::WordIdTable tableA;
    const std::vector<size_t> ids = tableA.getIds(words);

    std::ofstream file(filename);
    ASSERT_FALSE(file.fail());
    for (const std::string& word:words)
        file << word << std::endl;
    file.flush();

    tinylex::WordIdTable tableB;
    tableB.restore(filename);
    EXPECT_THAT(tableB.getIds(words), testing::Pointwise(testing::Eq(), ids));
}

TEST(TestWordIdTable, clear)
{
    tinylex::WordIdTable table;
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

    tinylex::DocumentIdTable table;
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