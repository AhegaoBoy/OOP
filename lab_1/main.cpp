#include <iostream>
#include "solution.h"
#include <gtest/gtest.h>

#include <gtest/gtest.h>


TEST(ValidParenthesesTest, EmptyString)
{
    EXPECT_TRUE(isValidParentheses(""));
}

TEST(ValidParenthesesTest, SinglePair)
{
    EXPECT_TRUE(isValidParentheses("()"));
}

TEST(ValidParenthesesTest, MultiplePairs)
{
    EXPECT_TRUE(isValidParentheses("(())"));
}

TEST(ValidParenthesesTest, InvalidSingleClosing)
{
    EXPECT_FALSE(isValidParentheses(")"));
}

TEST(ValidParenthesesTest, InvalidSingleOpening)
{
    EXPECT_FALSE(isValidParentheses("("));
}

TEST(ValidParenthesesTest, IncorrectOrder)
{
    EXPECT_FALSE(isValidParentheses("())"));
}

TEST(ValidParenthesesTest, OnlyOpeningBrackets)
{
    EXPECT_FALSE(isValidParentheses("((("));
}

TEST(ValidParenthesesTest, OnlyClosingBrackets)
{
    EXPECT_FALSE(isValidParentheses(")))"));
}

TEST(ValidParenthesesTest, MixedValid)
{
    EXPECT_TRUE(isValidParentheses("()()"));
}

TEST(ValidParenthesesTest, MixedInvalid)
{
    EXPECT_FALSE(isValidParentheses("(()))("));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}