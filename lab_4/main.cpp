#include <iostream>
#include "gtest/gtest.h"

#include "hexagon.h"
#include "rhomb.h"
#include "pentagon.h"
#include "Vector.h"
#include <iostream>


TEST(test_rhomb, test_init01)
{
    Rhomb<int> fig1;
    Point<int> p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point<int> p4 = p0;
    Rhomb<int> fig2(p1,p2,p3,p4);

    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_rhomb, test_init02)
{
    Rhomb<int> fig1;
    Point<int> p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point<int> p4 = p0;
    Rhomb<int> fig2(p1,p2,p3,p4);
    fig1 = fig2;
    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_rhomb, test_init03)
{
    Rhomb<double> fig1;
    Point<double> p1(-4.0, 0.0), p2(0.0, 5.0), p3(4.0, 0.0), p0(0.0, -5.0);
    Point<double> p4 = p0;
    Rhomb<double> fig2(p1,p2,p3,p4);
    fig1 = fig2;
    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_rhomb, test_square01)
{
    Point<int> p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point<int> p4 = p0;
    Rhomb<int> fig2(p1,p2,p3,p4);
    double sqr = fig2;
    ASSERT_TRUE(sqr == 40.0);
}

TEST(test_rhomb, test_square02)
{
    Point<int> p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point<int> p4 = p0;
    Rhomb<int> fig2(p1,p2,p3,p4);
    ASSERT_TRUE(fig2.square() == 40.0);
}

TEST(test_rhomb, test_square03)
{
    Vector<int> arr;
    Point<int> p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    Point<int> p4 = p0;
    auto fig2 = make_unique<Rhomb<int>>(p1,p2,p3,p4);
    arr.push_back(move(fig2));
    ASSERT_TRUE(arr.get(0)->square() == 40.0);
}

TEST(test_rhomb, test_square04)
{
    Rhomb<int> fig;
    ASSERT_TRUE(fig.square() == 0.0);
}

TEST(test_rhomb, test_square05)
{
    Point<double> p1(-4.0, 0.0), p2(0.0, 5.0), p3(4.0, 0.0), p0(0.0, -5.0);
    Point<double> p4 = p0;
    Rhomb<double> fig2(p1,p2,p3,p4);
    ASSERT_TRUE(fig2.square() == 40.0);
}

TEST(test_rhomb, test_center_01)
{
    Point<int> p1(-4, 0), p2(0, 5), p3(4, 0), p5(0, -5);
    Point<int> p4 = p5;
    Point<int> p0(0, 0);
    Rhomb<int> fig2(p1,p2,p3,p4);
    ASSERT_TRUE(fig2.center() == p0);
}

TEST(test_rhomb, test_center_02)
{
    Vector<int> arr;
    Point<int> p1(-4, 0), p2(0, 5), p3(4, 0), p5(0, -5);
    Point<int> p4 = p5;
    Point<int> p0(0, 0);
    auto fig = make_unique<Rhomb<int>>(p1,p2,p3,p4);
    arr.push_back(move(fig));
    ASSERT_TRUE(arr.get(0)->center() == p0);
}

TEST(test_rhomb, test_center_03)
{
    Rhomb<int> fig;
    Point<int> p0;
    ASSERT_TRUE(fig.center() == p0);
}

TEST(test_rhomb, test_center_04)
{
    Point<double> p1(-4.0, 0.0), p2(0.0, 5.0), p3(4.0, 0.0), p4(0.0, -5.0);
    Point<double> p0;
    Rhomb<double> fig2(p1,p2,p3,p4);
    ASSERT_TRUE(fig2.center() == p0);
}



TEST(test_pentagon, test_init01)
{
    Pentagon<int> fig1;
    Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    Pentagon<int> fig2(p1,p2,p3,p4,p5);
    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_pentagon, test_init02)
{
    Pentagon<int> fig1;
    Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    Pentagon<int> fig2(p1,p2,p3,p4,p5);
    fig1 = fig2;
    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_pentagon, test_init03)
{
    Pentagon<double> fig1;
    Point<double> p1(0.0, -2.0), p2(1.0, -2.0), p3(1.0, 2.0), p4(-1.0, 0.0), p5(1.0, 0.0);
    Pentagon<double> fig2(p1,p2,p3,p4,p5);
    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_pentagon, test_square01)
{
    Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    Pentagon<int> fig(p1,p2,p3,p4,p5);
    ASSERT_TRUE(fig.square() == 3);
}

TEST(test_pentagon, test_square02)
{
    Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    Pentagon<int> fig(p1,p2,p3,p4,p5);
    double sqr = fig;
    ASSERT_TRUE(sqr == 3);
}

TEST(test_pentagon, test_square03)
{
    Vector<int> arr;
    Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    auto fig = make_unique<Pentagon<int>>(p1,p2,p3,p4,p5);
    arr.push_back(move(fig));
    ASSERT_TRUE(arr.get(0)->square() != 0);
}

TEST(test_pentagon, test_square04)
{
    Pentagon<int> fig;
    ASSERT_TRUE(fig.square() == 0);
}

TEST(test_pentagon, test_square05)
{
    Point<double> p1(0.0, -2.0), p2(1.0, -2.0), p3(1.0, 2.0), p4(-1.0, 0.0), p5(1.0, 0.0);
    Pentagon<double> fig(p1,p2,p3,p4,p5);
    ASSERT_TRUE(fig.square() == 3);
}

TEST(test_pentagon, test_center01)
{
    Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    Pentagon<int> fig(p1,p2,p3,p4,p5);
    Point<int> p0;
    ASSERT_TRUE(fig.center() == p0);
}

TEST(test_pentagon, test_center02)
{
    Vector<int> arr;
    Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    Point<int> p0;
    auto fig = make_unique<Pentagon<int>>(p1,p2,p3,p4,p5);
    arr.push_back(move(fig));
    ASSERT_TRUE(arr.get(0)->center() == p0);
}

TEST(test_pentagon, test_center03)
{
    Pentagon<int> fig;
    Point<int> p0;
    ASSERT_TRUE(fig.center() == p0);
}

TEST(test_pentagon, test_center04)
{
    Point<double> p1(0.0, -2.0), p2(1.0, -2.0), p3(1.0, 2.0), p4(-1.0, 0.0), p5(1.0, 0.0);
    Pentagon<double> fig(p1,p2,p3,p4,p5);
    Point<double> p0;
    ASSERT_FALSE(fig.center() == p0);
}



TEST(test_hexagon, test_init01)
{
    Hexagon<int> fig1;
    Point<int> p1(1, 1), p2(2, 0), p3(1, -1), p4(-1, -1), p5(-2, 0), p6(-1, 1);
    Hexagon<int> fig2(p1,p2,p3,p4,p5,p6);
    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_hexagon, test_init02)
{
    Hexagon<int> fig1;
    Point<int> p1(1, 1), p2(2, 0), p3(1, -1), p4(-1, -1), p5(-2, 0), p6(-1, 1);
    Hexagon<int> fig2(p1,p2,p3,p4,p5,p6);
    fig1 = fig2;
    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_hexagon, test_init03)
{
    Hexagon<double> fig1;
    Point<double> p1(1.0, 1.0), p2(2.0, 0.0), p3(1.0, -1.0), p4(-1.0, -1.0), p5(-2.0, 0.0), p6(-1.0, 1.0);
    Hexagon<double> fig2(p1,p2,p3,p4,p5,p6);
    ASSERT_FALSE(fig1 == fig2);
}

TEST(test_hexagon, test_square01)
{
    Point<int> p1(1, 1), p2(2, 0), p3(1, -1), p4(-1, -1), p5(-2, 0), p6(-1, 1);
    Hexagon<int> fig(p1,p2,p3,p4,p5,p6);
    ASSERT_TRUE(fig.square() != 0.0);
}

TEST(test_hexagon, test_square02)
{
    Point<int> p1(1, 1), p2(2, 0), p3(1, -1), p4(-1, -1), p5(-2, 0), p6(-1, 1);
    Hexagon<int> fig(p1,p2,p3,p4,p5,p6);
    double sqr = fig;
    ASSERT_TRUE(sqr != 0.0);
}

TEST(test_hexagon, test_square03)
{
    Vector<int> arr;
    Point<int> p1(1, 1), p2(2, 0), p3(1, -1), p4(-1, -1), p5(-2, 0), p6(-1, 1);
    auto fig = make_unique<Hexagon<int>>(p1,p2,p3,p4,p5,p6);
    arr.push_back(move(fig));
    ASSERT_TRUE(arr.get(0)->square() != 0.0);
}

TEST(test_hexagon, test_square04)
{
    Hexagon<int> fig;
    ASSERT_TRUE(fig.square() == 0);
}

TEST(test_hexagon, test_square05)
{
    Point<double> p1(1.0, 1.0), p2(2.0, 0.0), p3(1.0, -1.0), p4(-1.0, -1.0), p5(-2.0, 0.0), p6(-1.0, 1.0);
    Hexagon<double> fig(p1,p2,p3,p4,p5,p6);
    ASSERT_TRUE(fig.square() != 0.0);
}

TEST(test_hexagon, test_center01)
{
    Point<int> p1(1, 1), p2(2, 0), p3(1, -1), p4(-1, -1), p5(-2, 0), p6(-1, 1);
    Point<int> p0;
    Hexagon<int> fig(p1,p2,p3,p4,p5,p6);
    ASSERT_TRUE(fig.center() == p0);
}

TEST(test_hexagon, test_center02)
{
    Vector<int> arr;
    Point<int> p1(1, 1), p2(2, 0), p3(1, -1), p4(-1, -1), p5(-2, 0), p6(-1, 1);
    Point<int> p0;
    auto fig = make_unique<Hexagon<int>>(p1,p2,p3,p4,p5,p6);
    arr.push_back(move(fig));
    ASSERT_TRUE(arr.get(0)->center() == p0);
}

TEST(test_hexagon, test_center03)
{
    Hexagon<int> fig;
    Point<int> p0;
    ASSERT_TRUE(fig.center() == p0);
}

TEST(test_hexagon, test_center04)
{
    Point<double> p1(1.0, 1.0), p2(2.0, 0.0), p3(1.0, -1.0), p4(-1.0, -1.0), p5(-2.0, 0.0), p6(-1.0, 1.0);
    Hexagon<double> fig(p1,p2,p3,p4,p5,p6);
    Point<double> p0;
    ASSERT_TRUE(fig.center() == p0);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
