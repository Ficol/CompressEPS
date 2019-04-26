#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, int visible_length) : bounding_box(bounding_box), visible_length(visible_length), bitmap((std::get<1>(std::get<0>(bounding_box)) - (std::get<0>(std::get<0>(bounding_box)))), (std::get<1>(std::get<1>(bounding_box)) - (std::get<0>(std::get<1>(bounding_box)))))
{
    /**/
}

void Bitmap::fillBitmap(const Point left_down, const Point right_up)
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

Bitmap::Array2D::Array2D(const int width, const int height) :width(width), height(height)
{
    array = std::vector<bool>(width * height);
}

bool Bitmap::Array2D::index(const int x, const int y) const
{
    return array[y * width + x];
}