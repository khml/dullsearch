//
// Created by KHML on 2020/07/09.
//

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <tinylexer/lexer.hpp>

TEST(TestLexer, LEX)
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