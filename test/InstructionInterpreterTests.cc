#include <boost/test/unit_test.hpp>

#include <InstructionInterpreter.h>
#include <InstructionInterpreter.cc>

BOOST_AUTO_TEST_CASE( InstructionInterpreterConstructorTest_WhenNotExistingFile )
{
    BOOST_CHECK_THROW(InstructionInterpreter("NotExistingFile"), std::ios_base::failure);
}

BOOST_AUTO_TEST_CASE( checkFormatTest_WhenFileWithoutBoundingBoxDefined )
{
    BOOST_CHECK_THROW(InstructionInterpreter("../test/testFiles/NoBoundingBox").checkFormat(), std::invalid_argument);
}

/**/