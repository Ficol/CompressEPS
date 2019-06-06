#include <boost/test/unit_test.hpp>

#include <Chain.h>
#include <Chain.cc>

BOOST_AUTO_TEST_SUITE(addPointTests)

BOOST_AUTO_TEST_CASE(addPoint)
{
    Chain chain(2.0);
    chain.addPoint(Chain::Point(3.0, 4.0));
    BOOST_CHECK_EQUAL(chain.getPointAmount(), 1);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(writeInstructionsTests)

BOOST_AUTO_TEST_CASE(ChainEmpty)
{
    Chain chain(2.0);
    std::string chain_instruction;
    chain.writeInstructions(chain_instruction);
    BOOST_CHECK_EQUAL(chain_instruction, "");
}

BOOST_AUTO_TEST_CASE(ChainHasOnePoint)
{
    Chain chain(2.0);
    chain.addPoint(Chain::Point(1.0, 2.2));
    std::string chain_instruction;
    chain.writeInstructions(chain_instruction);
    BOOST_CHECK_EQUAL(chain_instruction, "");
}

BOOST_AUTO_TEST_CASE(ChainHasMorePoints)
{
    Chain chain(2.0);
    chain.setLineWidth(3);
    chain.addPoint(Chain::Point(1.0, 2.2));
    chain.addPoint(Chain::Point(2.0, 3.2));
    chain.addPoint(Chain::Point(3.0, 4.2));
    std::string chain_instruction;
    chain.writeInstructions(chain_instruction);
    BOOST_CHECK_EQUAL(chain_instruction, "newpath\n1.00 2.20 m\n1.00 1.00 l\n1.00 1.00 l\n3 setlinewidth\nstroke\n");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(simplifyTests)

BOOST_AUTO_TEST_CASE(TwoPoints)
{
    Chain chain(2.0);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(1.0, 1.5));
    chain.setLineWidth(2.0);
    chain.simplify();
    Chain chain2(2.0);
    chain2.addPoint(Chain::Point(0.0, 0.0));
    chain2.addPoint(Chain::Point(1.0, 1.5));
    chain2.setLineWidth(2.0);
    BOOST_CHECK(chain == chain2);
}

BOOST_AUTO_TEST_CASE(ThreeCollinearPoints)
{
    Chain chain(2.0);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(10.0, 15.0));
    chain.addPoint(Chain::Point(20.0, 30.0));
    chain.simplify();
    BOOST_CHECK_EQUAL(chain.getPointAmount(), 2);
}

BOOST_AUTO_TEST_CASE(ThreeNonCollinearPoints)
{
    Chain chain(2.0);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(10.0, 0.0));
    chain.addPoint(Chain::Point(10.0, 10.0));
    chain.simplify();
    BOOST_CHECK_EQUAL(chain.getPointAmount(), 3);
}

BOOST_AUTO_TEST_CASE(ThreeNonCollinearPointsVisibleLengthBigger)
{
    Chain chain(2.0);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(10.0, 0.0));
    chain.addPoint(Chain::Point(10.0, 1.0));
    chain.simplify();
    BOOST_CHECK_EQUAL(chain.getPointAmount(), 2);
}

BOOST_AUTO_TEST_SUITE_END()