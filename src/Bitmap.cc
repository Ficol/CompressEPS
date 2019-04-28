#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, double visible_length) : bounding_box(bounding_box), visible_length(visible_length), bitmap((bounding_box.second.first - bounding_box.first.first), (bounding_box.second.second - bounding_box.first.second))
{
    /**/
}

void Bitmap::addRectangle(const Box rectangle)
{
    /**/
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
    array = std::vector<bool>(ceil(width) * ceil(height));
}

bool Bitmap::Array2D::index(const int x, const int y) const
{
    return array[y * width + x];
}