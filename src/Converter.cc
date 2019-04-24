#include "Converter.h"

Converter::Converter(const std::string &input_file, const size_t width = 1000, const size_t height = 1000) : instruction_reader(input_file)
{
    instruction_reader.checkFormat();
    bitmap = std::make_unique<Bitmap>(instruction_reader.getBoundingBox(), width, height);
    instruction_reader.addChains(chains);
    instruction_reader.addRectangles(*bitmap);
}

void Converter::compress()
{
    bitmap->simplify();
    for(Chain &a : chains)
        a.simplify();
}