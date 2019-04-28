#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <utility>
#include <vector>

class Bitmap
{
public:
  using Point = std::pair<int, int>;
  using Box = std::pair<Point, Point>;
  Bitmap(const Box bounding_box, int visible_length);
  Bitmap(const Bitmap &) = delete;
  Bitmap &operator=(const Bitmap &) = delete;

  void addRectangle(const Point left_down, const Point right_down);
  void simplify();
  std::string writeInstructions() const;

private:
  void mergeCloseRectangles();
  void deleteSmallRectangles();

  const Box bounding_box;
  const int visible_length;
  class Array2D
  {
  public:
    Array2D(const int width, const int height);

    bool index(const int x, const int y) const;

    const int width;
    const int height;
  private:
    std::vector<bool> array;
  } bitmap;
};

#endif // BITMAP_H