#include <boost/test/unit_test.hpp>

#include <Bitmap.h>
#include <Bitmap.cc>

BOOST_AUTO_TEST_CASE( writeInstructionTest_WhenBitmapEmpty )
{
    Bitmap::Box box(Bitmap::Point(0.0, 10.0), Bitmap::Point(20.0, 60.0));
    Bitmap bitmap(box, 10.0);
    BOOST_CHECK( bitmap.writeInstructions() == "");
}

BOOST_AUTO_TEST_CASE( writeInstructionTest_WhenBitmapFilledWithOneRectangle )
{
    Bitmap::Box box(Bitmap::Point(0.0, 10.0), Bitmap::Point(20.0, 60.0));
    Bitmap bitmap(box, 10.0);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(0.0, 10.0), Bitmap::Point(20.0, 50.0)));
    BOOST_CHECK( bitmap.writeInstructions() == "0.0 10.0 20.0 40.0 r p2\n");
}

BOOST_AUTO_TEST_CASE( simplifyTest_WhenTwoRectanglesNextToEachOther )
{
    Bitmap::Box box(Bitmap::Point(0.0, 10.0), Bitmap::Point(20.0, 60.0));
    Bitmap bitmap(box, 10.0);
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)));
    bitmap.addRectangle(Bitmap::Box(Bitmap::Point(10.0, 0.0), Bitmap::Point(20.0, 10.0)));
    BOOST_CHECK( bitmap.writeInstructions() == "0.0 0.0 20.0 10.0 r p2\n");
}