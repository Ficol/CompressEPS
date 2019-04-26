#include "Converter.h"

Converter::Converter(const std::string &input_file, const size_t width = 1000) : instruction_interpreter(input_file)
{
    instruction_interpreter.checkFormat();
    instruction_interpreter.setChains(chains, width);
    instruction_interpreter.setBitmap(bitmap, width);
}

void Converter::compress()
{
    bitmap->simplify();
    for(Chain &a : chains)
        a.simplify();
}

void Converter::createOutputFile(const std::string &output_file = "output.eps")
{
    /*
    instruction_interpreter.getPrologue();
    bitmap.writeInstructions();
    for(const auto a : chains)
        a.writeInstruction();
    instruction_interpreter.getEpilogue()
    */
}