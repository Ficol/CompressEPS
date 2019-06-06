#include <boost/test/unit_test.hpp>

#include <InstructionInterpreter.h>
#include <InstructionInterpreter.cc>

BOOST_AUTO_TEST_SUITE(constructorTests)

BOOST_AUTO_TEST_CASE(WhenExistingFile)
{
    BOOST_CHECK_NO_THROW(InstructionInterpreter("../test/testFiles/Empty.eps"));
}

BOOST_AUTO_TEST_CASE(WhenNotExistingFile)
{
    BOOST_CHECK_THROW(InstructionInterpreter("NotExistingFile"), std::ios_base::failure);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(checkFormatTests)

BOOST_AUTO_TEST_CASE(FileCorrect)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Correct.eps");
    BOOST_CHECK_NO_THROW(instruction_interpreter.checkFormat());
}

BOOST_AUTO_TEST_CASE(FileWithoutBoundingBoxDefined)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/NoBoundingBox.eps");
    BOOST_CHECK_THROW(instruction_interpreter.checkFormat(), std::ios_base::failure);
}

BOOST_AUTO_TEST_CASE(FileWithoutPSAdobeDeclaration)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/NoPSAdobe.eps");
    BOOST_CHECK_THROW(instruction_interpreter.checkFormat(), std::ios_base::failure);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(setChainsTests)

BOOST_AUTO_TEST_CASE(NoChains)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Correct.eps");
    std::vector<Chain> chains;
    std::vector<Chain> chains2;
    instruction_interpreter.setChains(chains, 1);
    BOOST_CHECK(chains == chains2);
}

BOOST_AUTO_TEST_CASE(simpleChain)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Chain.eps");
    std::vector<Chain> chains;
    std::vector<Chain> chains2;
    Chain chain(1.0);
    chain.setLineWidth(2);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(2.0, 2.0));
    chain.addPoint(Chain::Point(7.0, 7.0));
    chains2.push_back(chain);
    instruction_interpreter.setChains(chains, 1);
    BOOST_CHECK(chains == chains2);
}

BOOST_AUTO_TEST_CASE(TwoSimpleChains)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Chains.eps");
    std::vector<Chain> chains;
    std::vector<Chain> chains2;
    Chain chain(1.0);
    chain.setLineWidth(2);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(2.0, 2.0));
    chain.addPoint(Chain::Point(7.0, 7.0));
    chains2.push_back(chain);
    chain.clear();
    chain.addPoint(Chain::Point(1.0, 1.0));
    chain.addPoint(Chain::Point(4.0, 4.0));
    chain.addPoint(Chain::Point(10.0, 10.0));
    chains2.push_back(chain);
    instruction_interpreter.setChains(chains, 1);
    BOOST_CHECK(chains == chains2);
}

BOOST_AUTO_TEST_CASE(TwoChainsMove)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Chains2.eps");
    std::vector<Chain> chains;
    std::vector<Chain> chains2;
    Chain chain(1.0);
    chain.setLineWidth(4);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(2.0, 2.0));
    chain.addPoint(Chain::Point(7.0, 7.0));
    chains2.push_back(chain);
    chain.clear();
    chain.addPoint(Chain::Point(1.0, 1.0));
    chain.addPoint(Chain::Point(4.0, 4.0));
    chain.addPoint(Chain::Point(10.0, 10.0));
    chains2.push_back(chain);
    instruction_interpreter.setChains(chains, 1);
    BOOST_CHECK(chains == chains2);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(setBitmapTests)

BOOST_AUTO_TEST_CASE(NoRectangles)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Correct.eps");
    std::unique_ptr<Bitmap> bitmap = std::make_unique<Bitmap>(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    instruction_interpreter.setBitmap(bitmap, 1);
    Bitmap bitmap2(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 10);
    BOOST_CHECK(*bitmap == bitmap2);
}

BOOST_AUTO_TEST_CASE(OneRectangle)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Rectangle.eps");
    std::unique_ptr<Bitmap> bitmap = std::make_unique<Bitmap>(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    instruction_interpreter.setBitmap(bitmap, 1);
    Bitmap bitmap2(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 10);
    bitmap2.addRectangle(Bitmap::Box(Bitmap::Point(10.0, 10.0), Bitmap::Point(15.0, 15.0)));
    BOOST_CHECK(*bitmap == bitmap2);
}

BOOST_AUTO_TEST_CASE(TwoRectangles)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Rectangles.eps");
    std::unique_ptr<Bitmap> bitmap = std::make_unique<Bitmap>(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 1);
    instruction_interpreter.setBitmap(bitmap, 1);
    Bitmap bitmap2(Bitmap::Box(Bitmap::Point(0.0, 0.0), Bitmap::Point(10.0, 10.0)), 10);
    bitmap2.addRectangle(Bitmap::Box(Bitmap::Point(10.0, 10.0), Bitmap::Point(15.0, 15.0)));
    bitmap2.addRectangle(Bitmap::Box(Bitmap::Point(15.0, 15.0), Bitmap::Point(20.0, 20.0)));
    BOOST_CHECK(*bitmap == bitmap2);
}

BOOST_AUTO_TEST_CASE(TwoChainsMove)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Chains2.eps");
    std::vector<Chain> chains;
    std::vector<Chain> chains2;
    Chain chain(1.0);
    chain.setLineWidth(4);
    chain.addPoint(Chain::Point(0.0, 0.0));
    chain.addPoint(Chain::Point(2.0, 2.0));
    chain.addPoint(Chain::Point(7.0, 7.0));
    chains2.push_back(chain);
    chain.clear();
    chain.addPoint(Chain::Point(1.0, 1.0));
    chain.addPoint(Chain::Point(4.0, 4.0));
    chain.addPoint(Chain::Point(10.0, 10.0));
    chains2.push_back(chain);
    instruction_interpreter.setChains(chains, 1);
    BOOST_CHECK(chains == chains2);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(setPrologueTests)

BOOST_AUTO_TEST_CASE(Prologue)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Correct.eps");
    std::string prologue;
    instruction_interpreter.setPrologue(prologue);
    std::string prologue2 = "%%!PS-Adobe-3.0 EPSF-3.0\n"
                            "%%Title: R Graphics Output\n"
                            "%%Creator: R Software\n"
                            "%%Pages: (atend)\n"
                            "%%BoundingBox: 0.000000 0.000000 10.000000 10.000000\n"
                            "/m   { moveto } bind def\n"
                            "/l  { rlineto } bind def\n"
                            "/gs  { gsave } bind def\n"
                            "/bg { 0 0 0 srgb } def\n"
                            "/srgb { setcolor } bind def\n"
                            "/r   { 4 2 roll moveto 1 copy 3 -1 roll exch 0 exch rlineto 0 rlineto -1 mul 0 exch rlineto closepath } bind def\n"
                            "/p2  { gsave bg fill grestore newpath } bind def\n";
    BOOST_CHECK_EQUAL(prologue, prologue2);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(setEpilogueTests)

BOOST_AUTO_TEST_CASE(Prologue)
{
    InstructionInterpreter instruction_interpreter("../test/testFiles/Correct.eps");
    std::string epilogue;
    instruction_interpreter.setEpilogue(epilogue);
    std::string epilogue2 = "showpage";
    BOOST_CHECK_EQUAL(epilogue, epilogue2);
}

BOOST_AUTO_TEST_SUITE_END()