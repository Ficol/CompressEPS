#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, double visible_length) : bounding_box(bounding_box), visible_length(visible_length), bitmap((bounding_box.second.first - bounding_box.first.first), (bounding_box.second.second - bounding_box.first.second))
{
    /**/
}

void Bitmap::addRectangle(const Box rectangle)
{
    for(int i = rectangle.first.second; i != rectangle.second.second; ++i)
    {
        for(int j = rectangle.first.first; i != rectangle.second.first; ++j)
        {
            bitmap.get(i, j) = 1;
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
    /**/
}

void Bitmap::deleteSmallRectangles()
{
    /**/
}

Bitmap::Array2D::Array2D(const double width, const double height) : width(ceil(width))
{
    array = std::vector<char>(ceil(width) * ceil(height));
}

char &Bitmap::Array2D::get(const int x, const int y)
{
    return array[y * width + x];
}