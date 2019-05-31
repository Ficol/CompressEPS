#include "InstructionInterpreter.h"

InstructionInterpreter::InstructionInterpreter(const std::string &file_name)
{
    eps_file.open(file_name);
    if (!eps_file.is_open())
        throw std::ios_base::failure("Can't open output file\n");
}

InstructionInterpreter::~InstructionInterpreter()
{
    eps_file.close();
}

void InstructionInterpreter::checkFormat()
{
    std::string line;
    bool format = false;
    while (std::getline(eps_file, line))
    {
        if (line.find("%%BoundingBox:") != std::string::npos)
        {
            format = true;
            break;
        }
    }
    if (!format)
        throw std::ios_base::failure("Bounding box not defined in file");
    eps_file.clear();
    eps_file.seekg(0, std::ios::beg);
    format = false;
    while (std::getline(eps_file, line))
    {
        if (line.find("%!PS-Adobe-3.0") != std::string::npos)
        {
            format = true;
            break;
        }
    }
    if (!format)
        throw std::ios_base::failure("Bounding box not defined in file");
}

InstructionInterpreter::Box InstructionInterpreter::getBoundingBox()
{
    
}

void InstructionInterpreter::setChains(std::vector<Chain> &chains, const int target_width)
{
}

void InstructionInterpreter::setBitmap(std::unique_ptr<Bitmap> &bitmap, const int target_width)
{
    /**/
}

void InstructionInterpreter::setPrologue(std::string &prologue)
{
    /**/
}

void InstructionInterpreter::setEpilogue(std::string &prologue)
{
    /**/
}