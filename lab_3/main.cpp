#include <iostream>
#include "gtest/gtest.h"

#include <gtest/gtest.h>
#include "hexagon.h"
#include "rhomb.h"
#include "pentagon.h"
#include "Vector.h"
#include <iostream>

using namespace std;



TEST(test_rhomb, test_init01)
{
    Rhomb fig1;
    Point p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point p4 = p0;
    Rhomb fig2(p1,p2,p3,p4);

    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_rhomb, test_init02)
{
    Rhomb fig1;
    Point p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point p4 = p0;
    Rhomb fig2(p1,p2,p3,p4);
    fig1 = fig2;
    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_rhomb, test_square01)
{
    Point p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point p4 = p0;
    Rhomb fig2(p1,p2,p3,p4);
    double sqr = fig2;
    ASSERT_TRUE(sqr == 40.0);
}

TEST(test_rhomb, test_square02)
{
    Point p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point p4 = p0;
    Rhomb fig2(p1,p2,p3,p4);
    ASSERT_TRUE(fig2.square() == 40.0);
}

TEST(test_rhomb, test_square03)
{
    Vector arr;
    Point p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point p4 = p0;
    Rhomb fig2(p1,p2,p3,p4);
    arr.push_back(&fig2);
    ASSERT_TRUE(arr[0]->square() == 40.0);
}

TEST(test_rhomb, test_square04)
{
    Rhomb fig;
    ASSERT_TRUE(fig.square() == 0.0);
}

TEST(test_rhomb, test_center_01)
{
    Point p1(-4, 0), p2(0, 5), p3(4, 0), p5(0, -5);
    Point p4 = p5;
    Point p0(0, 0);
    Rhomb fig2(p1,p2,p3,p4);
    ASSERT_TRUE(fig2.center() == p0);
}

TEST(test_rhomb, test_center_02)
{
    Vector arr;
    Point p1(-4, 0), p2(0, 5), p3(4, 0), p5(0, -5);
    Point p4 = p5;
    Point p0(0, 0);
    Rhomb fig2(p1,p2,p3,p4);
    arr.push_back(&fig2);
    ASSERT_TRUE(arr[0]->center() == p0);
}

TEST(test_rhomb, test_center_03)
{
    Rhomb fig;
    Point p0;
    ASSERT_TRUE(fig.center() == p0);
}



TEST(test_pentagon, test_init01)
{
    Pentagon fig1;
    Point p1(2, -3), p2(3, -1), p3(5, -3), p4(4, 4), p5(4, -4);
    Pentagon fig2(p1,p2,p3,p4,p5);
    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_pentagon, test_init02)
{
    Pentagon fig1;
    Point p1(2, -3), p2(3, -1), p3(5, -3), p4(4, 4), p5(4, -4);
    Pentagon fig2(p1,p2,p3,p4,p5);
    fig1 = fig2;
    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_pentagon, test_square01)
{
    Point p1(2, -3), p2(3, -1), p3(5, -3), p4(4, 4), p5(4, -4);
    Pentagon fig(p1,p2,p3,p4,p5);
    ASSERT_TRUE(fig.square() != 0);
}

TEST(test_pentagon, test_square02)
{
    Point p1(2, -3), p2(3, -1), p3(5, -3), p4(4, 4), p5(4, -4);
    Pentagon fig(p1,p2,p3,p4,p5);
    double sqr = fig;
    ASSERT_TRUE(sqr != 0);
}

TEST(test_pentagon, test_square03)
{
    Vector arr;
    Point p1(2, -3), p2(3, -1), p3(5, -3), p4(4, 4), p5(4, -4);
    Pentagon fig(p1,p2,p3,p4,p5);
    arr.push_back(&fig);
    ASSERT_TRUE(arr[0]->square() != 0);
}

TEST(test_pentagon, test_square04)
{
    Pentagon fig;
    ASSERT_TRUE(fig.square() == 0);
}

TEST(test_pentagon, test_center01)
{
    Point p1(2, -3), p2(3, -1), p3(5, -3), p4(4, 4), p5(4, -4);
    Pentagon fig(p1,p2,p3,p4,p5);
    Point p0;
    ASSERT_TRUE(fig.center() != p0);
}

TEST(test_pentagon, test_center02)
{
    Vector arr;
    Point p1(2, -3), p2(3, -1), p3(5, -3), p4(4, 4), p5(4, -4);
    Pentagon fig(p1,p2,p3,p4,p5);
    Point p0;
    arr.push_back(&fig);
    ASSERT_TRUE(arr[0]->center() != p0);
}

TEST(test_pentagon, test_center03)
{
    Pentagon fig;
    Point p0;
    ASSERT_TRUE(fig.center() == p0);
}



TEST(test_hexagon, test_init01)
{
    Hexagon fig1;
    Point p1(-1, -1), p2(-2, -3), p3(-4, -3), p4(2, 3), p5(5, 1), p6(-5, -1);
    Hexagon fig2(p1,p2,p3,p4,p5,p6);
    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_hexagon, test_init02)
{
    Hexagon fig1;
    Point p1(-1, -1), p2(-2, -3), p3(-4, -3), p4(2, 3), p5(5, 1), p6(-5, -1);
    Hexagon fig2(p1,p2,p3,p4,p5,p6);
    fig1 = fig2;
    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_hexagon, test_square01)
{
    Point p1(-1, -1), p2(-2, -3), p3(-4, -3), p4(2, 3), p5(5, 1), p6(-5, -1);
    Hexagon fig(p1,p2,p3,p4,p5,p6);
    ASSERT_TRUE(fig.square() != 0.0);
}

TEST(test_hexagon, test_square02)
{
    Point p1(-1, -1), p2(-2, -3), p3(-4, -3), p4(2, 3), p5(5, 1), p6(-5, -1);
    Hexagon fig(p1,p2,p3,p4,p5,p6);
    double sqr = fig;
    ASSERT_TRUE(sqr != 0.0);
}

TEST(test_hexagon, test_square03)
{
    Vector arr;
    Point p1(-1, -1), p2(-2, -3), p3(-4, -3), p4(2, 3), p5(5, 1), p6(-5, -1);
    Hexagon fig(p1,p2,p3,p4,p5,p6);
    arr.push_back(&fig);
    ASSERT_TRUE(arr[0]->square() != 0.0);
}

TEST(test_hexagon, test_square04)
{
    Hexagon fig;
    ASSERT_TRUE(fig.square() == 0);
}

TEST(test_hexagon, test_center01)
{
    Point p1(-1, -1), p2(-2, -3), p3(-4, -3), p4(2, 3), p5(5, 1), p6(-5, -1);
    Point p0;
    Hexagon fig(p1,p2,p3,p4,p5,p6);
    ASSERT_TRUE(fig.center() != p0);
}

TEST(test_hexagon, test_center02)
{
    Vector arr;
    Point p1(-1, -1), p2(-2, -3), p3(-4, -3), p4(2, 3), p5(5, 1), p6(-5, -1);
    Point p0;
    Hexagon fig(p1,p2,p3,p4,p5,p6);
    arr.push_back(&fig);
    ASSERT_TRUE(arr[0]->center() != p0);
}

TEST(test_hexagon, test_center03)
{
    Hexagon fig;
    Point p0;
    ASSERT_TRUE(fig.center() == p0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}