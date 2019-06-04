#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, double visible_length) : bounding_box(bounding_box), visible_length(visible_length), bitmap((bounding_box.second.first - bounding_box.first.first) / visible_length, (bounding_box.second.second - bounding_box.first.second) / visible_length)
{
}

void Bitmap::addRectangle(const Box rectangle)
{
    for (size_t i = static_cast<size_t>(std::round(std::max(rectangle.first.second - bounding_box.first.second, 0.0) / visible_length)); i != static_cast<size_t>(std::round((rectangle.second.second - bounding_box.first.second) / visible_length)) && i != bitmap.height; ++i)
    {
        for (size_t j = static_cast<size_t>(std::round(std::max(rectangle.first.first - bounding_box.first.first, 0.0) / visible_length)); j != static_cast<size_t>(std::round((rectangle.second.first - bounding_box.first.second) / visible_length)) && j != bitmap.width; ++j)
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
            if (bitmap.index(j, i) == filled)
            {
                instruction << (j * visible_length + bounding_box.first.first) << " " << (i * visible_length + bounding_box.first.second) << " ";
                size_t width = measureRectangleWidth(j, i);
                size_t height = measureRectangleHeight(j, i);
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
            if (bitmap.index(j, i) == filled)
            {
                size_t width = measureRectangleWidth(j, i);
                size_t height = measureRectangleHeight(j, i);
                if (width < visible_length && height < visible_length)
                    deleteRectangle(j, i, width, height);
            }
        }
    }
}

size_t Bitmap::measureRectangleWidth(size_t x, size_t y)
{
    size_t rectangle_width = bitmap.width;
    size_t tmp = x;
    for (; bitmap.index(x, y) != empty && y != bitmap.height; ++y)
    {
        for (; bitmap.index(x, y) != empty && x != bitmap.width; ++x)
        {}
        rectangle_width = std::min(rectangle_width, x);
    }
    return rectangle_width - tmp;
}

size_t Bitmap::measureRectangleHeight(size_t x, size_t y)
{
    size_t rectangle_height = bitmap.height;
    size_t tmp = y;
    for (; bitmap.index(x, y) != empty && x != bitmap.width; ++x)
    {
        for (; bitmap.index(x, y) != empty && y != bitmap.height; ++y)
        {}
        rectangle_height = std::min(rectangle_height, y);
    }
    return rectangle_height - tmp;
}

void Bitmap::setRectangleWritten(size_t x, size_t y, size_t width, size_t height)
{
    for(size_t i = y; i != y + height; ++i)
    {
        for(size_t j = x; j != x + width; ++j)
        {
            bitmap.index(j, i) = written;
        }
    }
}

void Bitmap::deleteRectangle(size_t x, size_t y, size_t width, size_t height)
{
    for(size_t i = y; i != y + height; ++i)
    {
        for(size_t j = x; j != x + width; ++j)
        {
            bitmap.index(j, i) = empty;
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