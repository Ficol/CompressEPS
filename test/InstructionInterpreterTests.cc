#include <boost/test/unit_test.hpp>

#include <InstructionInterpreter.h>
#include <InstructionInterpreter.cc>

BOOST_AUTO_TEST_CASE( InstructionInterpreterConstructorTest_WhenNotExistingFile )
{
    BOOST_CHECK_THROW(InstructionInterpreter("NotExistingFile"), std::ios_base::failure);
}

BOOST_AUTO_TEST_CASE( checkFormatTest_WhenFileWithoutBoundingBoxDefined )
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/NoBoundingBox");
    BOOST_CHECK_THROW(instruction_interpreter.checkFormat(), std::invalid_argument);
}

/**/