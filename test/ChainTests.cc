#include <boost/test/unit_test.hpp>

#include <Chain.h>
#include <Chain.cc>

BOOST_AUTO_TEST_CASE(writeInstructionTest_WhenChainHasOnePoint)
{
    Chain chain(2.0, 3.0);
    chain.addPoint(Chain::Point(0.0, 0.0));
    
}

BOOST_AUTO_TEST_CASE(writeInstructionTest_WhenChainHasTwoPoints)
{
    Chain chain(2.0, 3.0);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(2.0, 3.0));
    
}

BOOST_AUTO_TEST_CASE(simplifyTest_WhenThreePointsCollinear)
{
    Chain chain(2.0, 3.0);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(1.0, 1.5));
    chain.addPoint(Chain::Point(2.0, 3.0));
    
}

/**/