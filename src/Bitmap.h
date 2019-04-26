#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <utility>
#include <memory>

class Bitmap
{
public:
  using Point = std::pair<int, int>;
  using Box = std::pair<Point, Point>;
  Bitmap(const Box bounding_box, size_t visible_length);
  Bitmap(const Bitmap &) = delete;
  Bitmap &operator=(const Bitmap &) = delete;

  void fillBitmap(const Point left_down, const Point right_down);
  void simplify();
  std::string writeInstructions() const;

private:
  void mergeCloseRectangles();
  void deleteSmallRectangles();

  class Array2D
  {
  public:
    Array2D(const Bitmap::Box bounding_box);

    bool index(const size_t x, const size_t y) const;

  private:
    const Bitmap::Box bounding_box;
    std::unique_ptr<bool[]> array;
  } array;
  const size_t visible_length;
};

#endif //BITMAP_H