/**
 * @file Bitmap.cc
 * @author Jakub Ficek
 * @brief File containing implemented methods of Bitmap class
 * 
 * 
 */

#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, double visible_length) : bounding_box(bounding_box), visible_length(visible_length), bitmap((bounding_box.second.first - bounding_box.first.first) / visible_length, (bounding_box.second.second - bounding_box.first.second) / visible_length)
{
}

bool Bitmap::operator==(const Bitmap &other_bitmap) const
{
    if (bitmap.width != other_bitmap.bitmap.width || bitmap.height != other_bitmap.bitmap.height)
        return false;
    for (size_t i = 0; i != bitmap.height; ++i)
    {
        for (size_t j = 0; j != bitmap.width; ++j)
        {
            if (bitmap.get(j, i) != other_bitmap.bitmap.get(j, i) && (bitmap.get(j, i) == empty || bitmap.get(j, i) == empty))
                return false;
        }
    }
    return true;
}

bool Bitmap::operator!=(const Bitmap &other_bitmap) const
{
    return !(*this == other_bitmap);
}

void Bitmap::addRectangle(const Box rectangle)
{
    for (size_t i = static_cast<size_t>(std::round(std::max(rectangle.first.second - bounding_box.first.second, 0.0) / visible_length)); i < static_cast<size_t>(std::round((std::max(rectangle.second.second - bounding_box.first.second, 0.0)) / visible_length)) && i < bitmap.height; ++i)
    {
        for (size_t j = static_cast<size_t>(std::round(std::max(rectangle.first.first - bounding_box.first.first, 0.0) / visible_length)); j < static_cast<size_t>(std::round((std::max(rectangle.second.first - bounding_box.first.second, 0.0)) / visible_length)) && j < bitmap.width; ++j)
        {
            bitmap.index(j, i) = filled;
        }
    }
}

void Bitmap::simplify()
{
    deleteSmallRectangles();
}

void Bitmap::writeInstructions(std::string &bitmap_instruction)
{
    std::ostringstream instruction;
    instruction << std::fixed;
    instruction << std::setprecision(2);
    for (size_t i = 0; i != bitmap.height; ++i)
    {
        for (size_t j = 0; j != bitmap.width; ++j)
        {
            if (bitmap.get(j, i) == filled)
            {
                instruction << (j * visible_length + bounding_box.first.first) << " " << (i * visible_length + bounding_box.first.second) << " ";
                size_t width = measureRectangleWidth(j, i);
                size_t height = measureRectangleHeight(j, i, width);
                instruction << (width * visible_length) << " " << (height * visible_length) << " r p2\n";
                setRectangleWritten(j, i, width, height);
            }
        }
    }
    bitmap_instruction = instruction.str();
}

void Bitmap::deleteSmallRectangles()
{
    for (size_t i = 0; i != bitmap.height; ++i)
    {
        for (size_t j = 0; j != bitmap.width; ++j)
        {
            if (bitmap.get(j, i) == filled)
            {
                if (bitmap.get(j + 1, i) == empty && bitmap.get(j, i + 1) == empty && bitmap.get(j - 1, i) == empty && bitmap.get(j, i - 1) == empty)
                    bitmap.index(j, i) = empty;
            }
        }
    }
}

size_t Bitmap::measureRectangleWidth(size_t x, size_t y)
{
    for (size_t i = x; i != bitmap.width; ++i)
    {
        if(bitmap.get(i, y) == empty)
            return i - x;
    }
    return bitmap.width - x;
}

size_t Bitmap::measureRectangleHeight(size_t x, size_t y, size_t width)
{
    for(size_t j = y; j != bitmap.height; ++j)
    {
        for(size_t i = x; i != x + width; ++i)
        {
            if(bitmap.get(i, j) == empty)
                return j - y;
        }
    }
    return bitmap.height - y;
}

void Bitmap::setRectangleWritten(size_t x, size_t y, size_t width, size_t height)
{
    for (size_t i = y; i != y + height; ++i)
    {
        for (size_t j = x; j != x + width; ++j)
        {
            bitmap.index(j, i) = written;
        }
    }
}

Bitmap::Array2D::Array2D(const double _width, const double _height) : width(ceil(_width)), height(ceil(_height))
{
    array = std::vector<state>(ceil(_width) * ceil(_height));
}

Bitmap::state &Bitmap::Array2D::index(const size_t x, const size_t y)
{
    return array[y * width + x];
}

Bitmap::state Bitmap::Array2D::get(const size_t x, const size_t y) const
{
    return array[y * width + x];
}