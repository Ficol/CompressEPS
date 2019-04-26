#include "InstructionInterpreter.h"

InstructionInterpreter::InstructionInterpreter(const std::string &file_name)
{
    /**/
}

void InstructionInterpreter::checkFormat() const
{
    /**/
}

InstructionInterpreter::Box InstructionInterpreter::getBoundingBox() const
{
    /**/
}

void InstructionInterpreter::setChains(std::vector<Chain> &chains, const int target_width) const
{
    /**/
}

void InstructionInterpreter::setBitmap(std::unique_ptr<Bitmap> &bitmap, const int target_width) const
{
    bitmap = std::make_unique<Bitmap>(getBoundingBox());
    /**/
}

std::string InstructionInterpreter::getPrologue() const
{
    /**/
}

std::string InstructionInterpreter::getEpilogue() const
{
    /**/
}