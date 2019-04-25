#include "InstructionReader.h"

InstructionReader::InstructionReader(const std::string &file_name)
{
    /**/
}

void InstructionReader::checkFormat() const
{
    /**/
}

InstructionReader::Box InstructionReader::getBoundingBox() const
{
    /**/
}

void InstructionReader::setChains(std::vector<Chain> &chains, const size_t width) const
{
    /**/
}

void InstructionReader::setBitmap(std::unique_ptr<Bitmap> &bitmap, const size_t width) const
{
    bitmap = std::make_unique<Bitmap>(getBoundingBox());
    /**/
}

std::string InstructionReader::getPrologue() const
{
    /**/
}

std::string InstructionReader::getEpilogue() const
{
    /**/
}