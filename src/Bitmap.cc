#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, double visible_length) : bounding_box(bounding_box), visible_length(visible_length), bitmap((bounding_box.second.first - bounding_box.first.first), (bounding_box.second.second - bounding_box.first.second))
{
    /**/
}

void Bitmap::addRectangle(const Box rectangle)
{
    for (int i = std::round(std::max(rectangle.first.second, bounding_box.first.second)); i < rectangle.second.second && i < bounding_box.second.second; ++i)
    {
        for (int j = std::round(std::max(rectangle.first.first, bounding_box.first.first)); j < rectangle.second.first && j < bounding_box.second.first; ++j)
        {
            bitmap.index(j, i) = filled;
        }
    }
}

void Bitmap::simplify()
{
    mergeCloseRectangles();
    deleteSmallRectangles();
}

void Bitmap::writeInstructions(std::string &bitmap_instruction)
{
    bitmap_instruction = "";
    std::string rectangle_instructions;
    for (int i = 0; i != bitmap.height; ++i)
    {
        for (int j = 0; j != bitmap.width; ++j)
        {
            if (bitmap.index(j, i) == filled)
            {
                bitmap_instruction.append(std::to_string(j) + " " + std::to_string(i) + " ");
                bitmap_instruction.append(std::to_string(MeasureRectangleWidth(j, i)) +  " " + std::to_string(MeasureRectangleHeight(j, i)) + " ");
                bitmap_instruction.append("r p2\n");
                setRectangleWritten(j, i);
            }
        }
    }
}

void Bitmap::mergeCloseRectangles()
{
    /*for(int i = 0; i != bitmap.height; ++i)
    {
        for(int j = 0; j != bitmap.width; ++j)
        {
            if(bitmap.index == filled)
        }
    }*/
}

void Bitmap::deleteSmallRectangles()
{
    for (int i = 0; i != bitmap.height; ++i)
    {
        for (int j = 0; j != bitmap.width; ++j)
        {
            if (bitmap.index(j, i) == filled && MeasureRectangleWidth(j, i) < visible_length && MeasureRectangleHeight(j, i) < visible_length)
                deleteRectangle(j, i);
        }
    }
}

int Bitmap::MeasureRectangleWidth(int x, int y)
{
    int rectangleWidth = 0;
    while (bitmap.index(x, y) != empty)
    {
        ++x;
        ++rectangleWidth;
    }
    return rectangleWidth;
}

int Bitmap::MeasureRectangleHeight(int x, int y)
{
    int rectangleHeight = 0;
    while (bitmap.index(x, y) != empty)
    {
        ++x;
        ++rectangleHeight;
    }
    return rectangleHeight;
}

void Bitmap::setRectangleWritten(int x, int y)
{
    int tmp = x;
    while (bitmap.index(x, y) != empty)
    {
        while (bitmap.index(x, y) != empty)
        {
            bitmap.index(x, y) = written;
            ++x;
        }
        x = tmp;
        ++y;
    }
}

void Bitmap::deleteRectangle(int x, int y)
{
    int tmp = x;
    while (bitmap.index(x, y) != empty)
    {
        while (bitmap.index(x, y) != empty)
        {
            bitmap.index(x, y) = empty;
            ++x;
        }
        x = tmp;
        ++y;
    }
}

Bitmap::Array2D::Array2D(const double width, const double height) : width(ceil(width)), height(ceil(height))
{
    array = std::vector<state>(ceil(width) * ceil(height));
}

Bitmap::state &Bitmap::Array2D::index(const int x, const int y)
{
    return array[y * width + x];
}