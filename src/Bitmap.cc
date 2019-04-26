#include "Bitmap.h"

Bitmap::Bitmap(const Box bounding_box, size_t visible_length) : array(bounding_box), visible_length(visible_length)
{
    /**/
}

void Bitmap::fillBitmap(const Point left_down, const Point right_down)
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

Bitmap::Array2D::Array2D(const Box bounding_box) : bounding_box(bounding_box)
{
    array = std::make_unique<bool[]>((std::get<1>(std::get<0>(bounding_box)) - (std::get<0>(std::get<0>(bounding_box))) + 1) * (std::get<1>(std::get<1>(bounding_box)) - (std::get<0>(std::get<1>(bounding_box))) + 1));
}

bool Bitmap::Array2D::index(const size_t x, const size_t y) const
{
    std::get<0>(std::get<1>(bounding_box));
    return array[(y - std::get<0>(std::get<1>(bounding_box))) * (x - std::get<0>(std::get<0>(bounding_box)) + 1) + x - std::get<0>(std::get<0>(bounding_box))];
}