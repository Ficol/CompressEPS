#include <boost/test/unit_test.hpp>

#include <Bitmap.h>
#include <Bitmap.cc>

BOOST_AUTO_TEST_SUITE(writeInstructionsTest)

BOOST_AUTO_TEST_CASE(emptyBitmap)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    std::string instruction;
    bitmap.writeInstructions(instruction);
    BOOST_CHECK_EQUAL(instruction, "");
}

BOOST_AUTO_TEST_CASE(twoSeparatedRectangles)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(2.0, 2.0)));
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(5.0, 1.0), Bitmap::Point(6.0, 3.0)));
    std::string instruction;
    bitmap.writeInstructions(instruction);
    BOOST_CHECK_EQUAL(instruction, "1.00 1.00 1.00 1.00 r p2\n5.00 1.00 1.00 2.00 r p2\n");
}

BOOST_AUTO_TEST_CASE(twoAdjacentRectangles)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(2.0, 2.0)));
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(2.0, 1.0), Bitmap::Point(3.0, 2.0)));
    std::string instruction;
    bitmap.writeInstructions(instruction);
    BOOST_CHECK_EQUAL(instruction, "1.00 1.00 2.00 1.00 r p2\n");
}

BOOST_AUTO_TEST_CASE(twoCoveringRectangles)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(3.0, 3.0)));
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(2.0, 2.0), Bitmap::Point(4.0, 4.0)));
    std::string instruction;
    bitmap.writeInstructions(instruction);
    BOOST_CHECK_EQUAL(instruction, "1.00 1.00 2.00 2.00 r p2\n3.00 2.00 1.00 2.00 r p2\n2.00 3.00 2.00 1.00 r p2\n");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(addRectangletTest)

BOOST_AUTO_TEST_CASE(addRectangle)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1.0);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(2.0, 2.0)));
    std::string instruction;
    bitmap.writeInstructions(instruction);
    BOOST_CHECK_EQUAL(instruction, "1.00 1.00 1.00 1.00 r p2\n");
}

BOOST_AUTO_TEST_CASE(addRectangleOutsideOfBoundingBox)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1.0);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(-1.0, -1.0), Bitmap::Point(2.0, 2.0)));
    Bitmap bitmap2(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1.0);
    bitmap2.addRectangle(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(2.0, 2.0)));
    BOOST_CHECK(bitmap == bitmap2);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(simplifyTest)

BOOST_AUTO_TEST_CASE(rectangleWidthTooBigToDelete)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 0.5);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(3.0, 1.5)));
    bitmap.simplify();
    Bitmap bitmap2(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 0.5);
    bitmap2.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(3.0, 1.5)));
    BOOST_CHECK(bitmap == bitmap2);
}

BOOST_AUTO_TEST_CASE(rectangleHeightTooBigToDelete)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 0.5);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(1.5, 3.0)));
    bitmap.simplify();
    Bitmap bitmap2(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 0.5);
    bitmap2.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(1.5, 3.0)));
    BOOST_CHECK(bitmap == bitmap2);
}

BOOST_AUTO_TEST_CASE(smallRectangle)
{
    Bitmap bitmap(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(1.0, 1.0), Bitmap::Point(1.5, 1.5)));
    bitmap.simplify();
    Bitmap bitmap2(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    BOOST_CHECK(bitmap == bitmap2);
}

BOOST_AUTO_TEST_SUITE_END()