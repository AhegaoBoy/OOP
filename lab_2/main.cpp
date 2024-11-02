#include <iostream>
#include "decimal.h"
#include "gtest/gtest.h"


TEST(assignment, test01) 
{
    decimal num1, num2("0");
    num1 = num2;
    ASSERT_TRUE(num1 == decimal("0"));
}

TEST(assignment, test02) {
    decimal num1("3242"), num2("4123");
    num1 = num2;
    ASSERT_TRUE(num1 == decimal("4123"));
}

TEST(assignment, test03) {
    decimal num1, num2("10000000000000");
    num1 = num2;
    ASSERT_TRUE(num1 == decimal("10000000000000"));
}



TEST(equal, test01) {
    decimal num1("0"), num2("0");
    ASSERT_TRUE(num1 == num2);
}

TEST(equal, test02) {
    decimal num1, num2("45");
    ASSERT_FALSE(num1 == num2);
}

TEST(equal, test03)
{
    decimal num1("1000000000000000"), num2("100000000");
    ASSERT_FALSE(num1 == num2);
}



TEST(not_equal, test01) {
    decimal num1("0"), num2("0");
    ASSERT_FALSE(num1 != num2);
}

TEST(not_equal, test02) {
    decimal num1, num2("222");
    ASSERT_TRUE(num1 != num2);
}

TEST(not_equal, test03) {
    decimal num1("1111111111"), num2("11111111111");
    ASSERT_TRUE(num1 != num2);
}



TEST (is_greater, test01) {
    decimal num1("0"), num2("1");
    ASSERT_FALSE(num1 > num2);
}

TEST(is_greater, test02) {
    decimal num1("134"), num2;
    ASSERT_TRUE(num1 > num2);
}

TEST(is_greater, test03)
{
    decimal num1("10000000000"), num2("1111111");
    ASSERT_TRUE(num1 > num2);
}



TEST(is_greater_or_equal, test01)
{
    decimal num1("0"), num2("0");
    ASSERT_TRUE(num1 >= num2);
}

TEST(is_greater_or_equal, test02)
{
    decimal num1("222"), num2;
    ASSERT_TRUE(num1 >= num1);
}

TEST(is_greater_or_equal, test03)
{
    decimal num1("11111111111"), num2("111111111111");
    ASSERT_FALSE(num1 >= num2);
}



TEST (is_less, test01) {
    decimal num1("0"), num2("1");
    ASSERT_TRUE(num1 < num2);
}

TEST(is_less, test02) {
    decimal num1("134"), num2;
    ASSERT_FALSE(num1 < num1);
}

TEST(is_less, test03) {
    decimal num1("10000000000"), num2("1111111");
    ASSERT_FALSE(num1 < num2);
}



TEST(is_less_or_equal, test01) {
    decimal num1("0"), num2("0");
    ASSERT_TRUE(num1 <= num2);
}

TEST(is_less_or_equal, test02) {
    decimal num1("222"), num2;
    ASSERT_FALSE(num1 <= num2);
}

TEST(is_less_or_equal, test03) {
    decimal num1("11111111111"), num2("111111111111");
    ASSERT_TRUE(num1 <= num2);
}



TEST(summ, test01)
{
    decimal num1, num2("0");
    ASSERT_TRUE(num1 + num2 == decimal("0"));
}

TEST(summ, test02) {
    decimal num1("111"), num2("111");
    ASSERT_TRUE(num1 + num2 == decimal("222"));
}

TEST(summ, test03)
{
    decimal num1("5000000000000000"), num2("1");
    ASSERT_TRUE(num1 + num2 == decimal("5000000000000001"));
}



TEST(diff, test01) {
    decimal num1, num2("0");
    ASSERT_TRUE(num2 - num1 == decimal("0"));
}

TEST(diff, test02) {
    decimal num1("100"), num2("1");
    ASSERT_TRUE(num1 - num2 == decimal("99"));
}

TEST(diff, test03) {
    decimal num1("1000000000000000"), num2("1");
    ASSERT_TRUE(num1 - num2 == decimal("999999999999999"));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}