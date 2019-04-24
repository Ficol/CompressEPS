#ifndef BITMAP_H
#define BITMAP_H

#include <string>

class Bitmap
{
  public:
    typedef std::pair<int, int> Point;
    typedef std::pair<Point, Point> Box;
    Bitmap(const Box &bounding_box, const size_t width, const size_t height);
    Bitmap(const Bitmap &) = delete;
    Bitmap &operator=(const Bitmap &) = delete;

    void fillBitmap(const Point left_down, const Point right_down);
    void simplify();
    std::string writeInstructions();

  private:
    void mergeCloseRectangles();
    void deleteSmallRectangles();

    struct Array2D
    {
        Array2D(const int width, const int height);
        ~Array2D();
        size_t index(const size_t x, const size_t y) const;
    } array;
    const size_t visible_width;
    const size_t visible_height;
};

#endif //BITMAP_H