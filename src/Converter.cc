#include "Converter.h"

Converter::Converter(const std::string &input_file, const int target_width) : instruction_interpreter(input_file)
{
    instruction_interpreter.checkFormat();
    instruction_interpreter.setChains(chains, target_width);
    instruction_interpreter.setBitmap(bitmap, target_width);
}

void Converter::compress()
{
    bitmap->simplify();
    for(Chain &a : chains)
        a.simplify();
}

void Converter::saveOutputFile(const std::string &output_file_name)
{
    output_file.open(output_file_name);
    if(!output_file.is_open())
        throw std::ios_base::failure("Can't open output file\n");
    output_file << instruction_interpreter.getPrologue()
    << bitmap->writeInstructions();
    for(const Chain &a : chains)
        output_file << a.writeInstructions();
    output_file << instruction_interpreter.getEpilogue();
    output_file.close();
}