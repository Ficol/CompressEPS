#include "Converter.h"

Converter::Converter(const std::string &input_file, const size_t target_width) : instruction_interpreter(input_file)
{
    instruction_interpreter.checkFormat();
    instruction_interpreter.setChains(chains, target_width);
    instruction_interpreter.setBitmap(bitmap, target_width);
}

void Converter::compress()
{
    bitmap->simplify();
    for (Chain &a : chains)
        a.simplify();
}

void Converter::saveOutputFile(const std::string &output_file_name)
{
    output_file.open(output_file_name);
    if (!output_file.is_open())
        throw std::ios_base::failure("Can't open/create output file\n");
    std::string eps_element;
    instruction_interpreter.setPrologue(eps_element);
    output_file << eps_element;
    bitmap->writeInstructions(eps_element);
    output_file << eps_element;
    for (const Chain &a : chains)
    {
        a.writeInstructions(eps_element);
        output_file << eps_element;
    }
    instruction_interpreter.setEpilogue(eps_element);
    output_file << eps_element;
    output_file.close();
}