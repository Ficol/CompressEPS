#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, double visible_length) : bounding_box(bounding_box), visible_length(visible_length), bitmap((bounding_box.second.first - bounding_box.first.first), (bounding_box.second.second - bounding_box.first.second))
{
    /**/
}

void Bitmap::addRectangle(const Box rectangle)
{
    for (int j = std::max(rectangle.first.second, bounding_box.first.second); j < rectangle.second.second && j < bounding_box.second.second; ++j)
    {
        for (int i = std::max(rectangle.first.first, bounding_box.first.first); i < rectangle.second.first && j < bounding_box.second.first; ++i)
        {
            bitmap.index(i, j) = filled;
        }
    }
}

void Bitmap::simplify()
{
    mergeCloseRectangles();
    deleteSmallRectangles();
}

std::string Bitmap::writeInstructions() const
{
    /**/
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
            if (bitmap.index == filled && isRectangleSmall(j, i))
                deleteRectangle(j, i);
        }
    }
}

bool Bitmap::isRectangleSmall(int x, int y)
{
    int rectangleLength = 0;
    while (bitmap.index(x, y) == filled)
    {
        ++x;
        ++rectangleLength;
    }
    if (rectangleLength >= visible_length)
        return false;
    rectangleLength = 0;
    while (bitmap.index(x, y) == filled)
    {
        ++y;
        ++rectangleLength;
    }
    if (rectangleLength >= visible_length)
        return false;
    return true;
}

void Bitmap::deleteRectangle(int x, int y)
{
    int tmp = x;
    while (bitmap.index(x, y) == filled)
    {
        while (bitmap.index(x, y) == filled)
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