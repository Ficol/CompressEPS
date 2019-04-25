#include "Converter.h"

Converter::Converter(const std::string &input_file, const size_t width = 1000) : instruction_reader(input_file)
{
    instruction_reader.checkFormat();
    instruction_reader.setChains(chains, width);
    instruction_reader.setBitmap(bitmap, width);
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
    instruction_reader.getPrologue();
    bitmap.writeInstructions();
    for(const auto a : chains)
        a.writeInstruction();
    instruction_reader.getEpilogue()
    */
}