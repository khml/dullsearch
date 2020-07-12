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
    ASSERT_THAT(tinylex::lex("Hello World!"),
        testing::ElementsAre("Hello", "World", "!"));

    ASSERT_THAT(tinylex::lex("1+2*3/6"),
        testing::ElementsAre("1", "+", "2", "*", "3", "/", "6"));

    ASSERT_THAT(tinylex::lex(
        "class HelloWorld { public static void main(String[] args) { System.out.println(\"Hello, world.\"); } }"),
        testing::ElementsAre("class", "HelloWorld", "{", "public", "static", "void", "main", "(", "String", "[", "]",
            "args", ")", "{", "System", ".", "out", ".", "println", "(", "Hello, world.", ")", ";", "}", "}"));
}

TEST(TestSymbol, toSymbol)
{
    ASSERT_EQ(tinylex::symbol::toSymbol("+"), tinylex::symbol::ADD);
    ASSERT_EQ(tinylex::symbol::toSymbol("-"), tinylex::symbol::SUB);
    ASSERT_EQ(tinylex::symbol::toSymbol("*"), tinylex::symbol::ASTERISK);
    ASSERT_EQ(tinylex::symbol::toSymbol("/"), tinylex::symbol::SLASH);
    ASSERT_EQ(tinylex::symbol::toSymbol("@"), tinylex::symbol::AT);
    ASSERT_EQ(tinylex::symbol::toSymbol("="), tinylex::symbol::EQUAL);
    ASSERT_EQ(tinylex::symbol::toSymbol(")"), tinylex::symbol::PARENTHESISE_RIGHT);
    ASSERT_EQ(tinylex::symbol::toSymbol("("), tinylex::symbol::PARENTHESIS_LEFT);
    ASSERT_EQ(tinylex::symbol::toSymbol("]"), tinylex::symbol::BRACKET_RIGHT);
    ASSERT_EQ(tinylex::symbol::toSymbol("["), tinylex::symbol::BRACKET_LEFT);
    ASSERT_EQ(tinylex::symbol::toSymbol("}"), tinylex::symbol::BRACE_RIGHT);
    ASSERT_EQ(tinylex::symbol::toSymbol("{"), tinylex::symbol::BRACE_LEFT);
    ASSERT_EQ(tinylex::symbol::toSymbol("."), tinylex::symbol::DOT);
    ASSERT_EQ(tinylex::symbol::toSymbol(","), tinylex::symbol::COMMA);
    ASSERT_EQ(tinylex::symbol::toSymbol(":"), tinylex::symbol::COLON);
    ASSERT_EQ(tinylex::symbol::toSymbol(";"), tinylex::symbol::SEMICOLON);
    ASSERT_EQ(tinylex::symbol::toSymbol("?"), tinylex::symbol::INTERROGATION);
    ASSERT_EQ(tinylex::symbol::toSymbol(">"), tinylex::symbol::GRATER_THAN);
    ASSERT_EQ(tinylex::symbol::toSymbol("<"), tinylex::symbol::LESSER_THAN);
    ASSERT_EQ(tinylex::symbol::toSymbol("\'"), tinylex::symbol::APOSTROPHE);
    ASSERT_EQ(tinylex::symbol::toSymbol("\""), tinylex::symbol::QUOTATION);
    ASSERT_EQ(tinylex::symbol::toSymbol("&"), tinylex::symbol::AMPERSAND);
    ASSERT_EQ(tinylex::symbol::toSymbol("%"), tinylex::symbol::PERCENT);
    ASSERT_EQ(tinylex::symbol::toSymbol("$"), tinylex::symbol::DOLLAR);
    ASSERT_EQ(tinylex::symbol::toSymbol("#"), tinylex::symbol::SHARP);
    ASSERT_EQ(tinylex::symbol::toSymbol("|"), tinylex::symbol::PIPE);
    ASSERT_EQ(tinylex::symbol::toSymbol("_"), tinylex::symbol::UNDER_BAR);
    ASSERT_EQ(tinylex::symbol::toSymbol("\\"), tinylex::symbol::BACKSLASH);
    ASSERT_EQ(tinylex::symbol::toSymbol(" "), tinylex::symbol::WHITESPACE);
    ASSERT_EQ(tinylex::symbol::toSymbol("\n"), tinylex::symbol::NEW_LINE);
    ASSERT_EQ(tinylex::symbol::toSymbol("=="), tinylex::symbol::EQUIVALENCE);
    ASSERT_EQ(tinylex::symbol::toSymbol(">="), tinylex::symbol::GRATER);
    ASSERT_EQ(tinylex::symbol::toSymbol("<="), tinylex::symbol::LESSER);
    ASSERT_EQ(tinylex::symbol::toSymbol("++"), tinylex::symbol::INCREMENTAL);
    ASSERT_EQ(tinylex::symbol::toSymbol("--"), tinylex::symbol::DECREMENTAL);
    ASSERT_EQ(tinylex::symbol::toSymbol("&&"), tinylex::symbol::AND);
    ASSERT_EQ(tinylex::symbol::toSymbol("||"), tinylex::symbol::OR);
    ASSERT_EQ(tinylex::symbol::toSymbol("/*"), tinylex::symbol::COMMENT_START);
    ASSERT_EQ(tinylex::symbol::toSymbol("*/"), tinylex::symbol::COMMENT_END);
    ASSERT_EQ(tinylex::symbol::toSymbol("->"), tinylex::symbol::ARROW);
    ASSERT_EQ(tinylex::symbol::toSymbol("=>"), tinylex::symbol::FAT_ARROW);
    ASSERT_EQ(tinylex::symbol::toSymbol("!"), tinylex::symbol::EXCLAMATION);
    ASSERT_EQ(tinylex::symbol::toSymbol("a"), tinylex::symbol::IDENTIFIER);
    ASSERT_EQ(tinylex::symbol::toSymbol("0"), tinylex::symbol::IDENTIFIER);
}

TEST(TestUtilities, isDigit)
{
    for (int i = 0; i < 20; i++)
        ASSERT_TRUE(tinylex::isDigit(std::to_string(i)));

    ASSERT_FALSE(tinylex::isDigit("a"));
    ASSERT_FALSE(tinylex::isDigit("1.1"));
}

TEST(TestUtilities, isFloat)
{
    ASSERT_TRUE(tinylex::isFloat("1.1f"));
    ASSERT_TRUE(tinylex::isFloat(".11f"));

    ASSERT_FALSE(tinylex::isFloat("10f"));
    ASSERT_FALSE(tinylex::isFloat("1.1.1f"));
    ASSERT_FALSE(tinylex::isFloat("1.1"));
    ASSERT_FALSE(tinylex::isFloat("f"));
    ASSERT_FALSE(tinylex::isFloat("a"));
}

TEST(TestUtilities, isDouble)
{
    ASSERT_TRUE(tinylex::isDouble("1.1"));
    ASSERT_TRUE(tinylex::isDouble("10.1"));
    ASSERT_TRUE(tinylex::isDouble("1.01"));
    ASSERT_TRUE(tinylex::isDouble(".100"));

    ASSERT_FALSE(tinylex::isDouble("100"));
    ASSERT_FALSE(tinylex::isDouble("a"));
}

TEST(TestUtilities, isIdentifier)
{
    ASSERT_TRUE(tinylex::isIdentifier("hello"));
    ASSERT_TRUE(tinylex::isIdentifier("_hello"));
    ASSERT_TRUE(tinylex::isIdentifier("hello_"));
    ASSERT_TRUE(tinylex::isIdentifier("Hello"));
    ASSERT_TRUE(tinylex::isIdentifier("WORLD"));
    ASSERT_TRUE(tinylex::isIdentifier("a100"));
}

TEST(TestUtilities, splitByComma)
{
    ASSERT_THAT(tinylex::splitByComma("1,2,3,4,5"),
        testing::ElementsAre("1", "2", "3", "4", "5"));

    ASSERT_THAT(tinylex::splitByComma("1, \"2\", ',3', a'4', 5"),
        testing::ElementsAre("1", "2", ",3", "a'4'", "5"));
}

TEST(TestUtilities, uniqSort)
{
    std::vector<size_t> source = {100, 1, 20, 2, 5, 100};
    tinylex::uniqSort(source);
    ASSERT_THAT(source, testing::ElementsAre(1, 2, 5, 20, 100));
}

TEST(TestUtilities, toStr)
{
    std::vector<size_t> source = {100, 1, 20, 2, 5};
    ASSERT_EQ(tinylex::toStr(source), "100, 1, 20, 2, 5");
}

TEST(TestUtilities, isDir)
{
    ASSERT_TRUE(tinylex::isDir("."));
    ASSERT_TRUE(tinylex::isDir(".."));

    const std::string filepath("dummy.txt");
    std::ofstream file(filepath);
    file.flush();
    ASSERT_FALSE(tinylex::isDir(filepath));
}

TEST(TestReadCsv, readCsvFile)
{
    const std::string filepath("dummy.csv");
    std::ofstream file(filepath);
    file << "0,1,2,3,4" << std::endl;
    file.flush();
    ASSERT_EQ(tinylex::readCsvFile(filepath).size(), 1);
    ASSERT_THAT(tinylex::readCsvFile(filepath)[0], testing::ElementsAre("0", "1", "2", "3", "4"));

    file << "5, 6,  7" << std::endl;
    file.flush();
    ASSERT_EQ(tinylex::readCsvFile(filepath).size(), 2);
    ASSERT_THAT(tinylex::readCsvFile(filepath)[1], testing::ElementsAre("5", "6", "7"));
}

TEST(TestWordIdTable, getId)
{
    tinylex::WordIdTable table;
    ASSERT_EQ(table.getId("Hello"), 1);
    ASSERT_EQ(table.getId("Hello"), 1);

    ASSERT_EQ(table.getId("World"), 2);
    ASSERT_EQ(table.getId("Hello"), 1);
}

TEST(TestWordIdTable, getIds)
{
    tinylex::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids = table.getIds(words);
    ASSERT_THAT(ids, testing::ElementsAre(1, 2, 3, 4, 5, 1, 2, 6, 3));

    ids = table.getIds(words);
    ASSERT_THAT(ids, testing::ElementsAre(1, 2, 3, 4, 5, 1, 2, 6, 3));

    words = {"This", "Is", "Test", "Code", "."};
    ids = table.getIds(words);
    ASSERT_THAT(ids, testing::ElementsAre(4, 5, 7, 6, 3));
}

TEST(TestWordIdTable, getIdsWithUniqSort)
{
    tinylex::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids_sorted = table.getIdsWithUniqSort(words);

    std::vector<std::size_t> ids = table.getIds(words);
    tinylex::uniqSort(ids);
    ASSERT_THAT(ids_sorted, ids);
}

TEST(TestWordIdTable, contain)
{
    tinylex::WordIdTable table;
    const std::string key = "Hello";
    ASSERT_FALSE(table.contain(key));
    ASSERT_FALSE(table.contain(key));

    table.getId(key);
    ASSERT_TRUE(table.contain(key));
}

TEST(TestWordIdTable, getValue)
{
    tinylex::WordIdTable table;
    const std::string key = "Hello";
    const size_t id = table.getId(key);
    ASSERT_EQ(table.getValue(id), key);
}

TEST(TestWordIdTable, unwrap)
{
    tinylex::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids = table.getIds(words);
    std::unordered_map<std::string, size_t> unwrapTable = table.unwrap();

    ASSERT_EQ(unwrapTable.size(), 6);

    for (size_t idx = 0; idx < words.size(); idx++)
    {
        ASSERT_EQ(unwrapTable[words[idx]], ids[idx]);
    }
}

TEST(TestWordIdTable, clear)
{
    tinylex::WordIdTable table;
    std::vector<std::string> words = {"Hello", "World", ".", "This", "Is", "Hello", "World", "Code", "."};
    std::vector<std::size_t> ids = table.getIds(words);
    std::unordered_map<std::string, size_t> unwrapTable = table.unwrap();

    ASSERT_EQ(unwrapTable.size(), 6);

    table.clear();
    unwrapTable = table.unwrap();
    ASSERT_EQ(unwrapTable.size(), 0);

    ASSERT_EQ(table.getId("hello"), 1);
    ASSERT_EQ(table.getId("world"), 2);
    table.clear();
    ASSERT_EQ(table.getId("world"), 1);
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

    ASSERT_THAT(table.lookupFiles("Hello"), testing::Contains(filepathA));
    ASSERT_THAT(table.lookupFiles("This"), testing::Not(testing::Contains(filepathA)));
    ASSERT_THAT(table.lookupFiles("This"), testing::Contains(filepathB));

    table.setIds(filepathC);
    ASSERT_THAT(table.lookupFiles("Hello"), testing::Contains(filepathA));
    ASSERT_THAT(table.lookupFiles("Hello"), testing::Contains(filepathC));
    ASSERT_THAT(table.lookupFiles("Hello"), testing::Not(testing::Contains(filepathB)));

    ASSERT_THAT(table.lookupFiles("program"), testing::Contains(filepathC));
    ASSERT_THAT(table.lookupFiles("program"), testing::Not(testing::Contains(filepathA)));
    ASSERT_THAT(table.lookupFiles("program"), testing::Not(testing::Contains(filepathB)));
}