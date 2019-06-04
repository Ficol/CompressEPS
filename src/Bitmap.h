#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>

class Bitmap
{
public:
  using Point = std::pair<double, double>;
  using Box = std::pair<Point, Point>;
  Bitmap(const Box bounding_box, double visible_length);
  Bitmap(const Bitmap &) = delete;
  Bitmap &operator=(const Bitmap &) = delete;
  enum state
  {
    empty,
    filled,
    written
  };
  void addRectangle(const Box rectangle);
  void simplify();
  void writeInstructions(std::string &bitmap_instruction);

private:
  void deleteSmallRectangles();
  size_t measureRectangleWidth(size_t x, size_t y);
  size_t measureRectangleHeight(size_t x, size_t y);
  void setRectangleWritten(size_t x, size_t y, size_t width, size_t height);
  void deleteRectangle(size_t x, size_t y, size_t width, size_t height);

  const Box bounding_box;
  const double visible_length;
  class Array2D
  {
  public:
    Array2D(const double width, const double height);

    enum state &index(const size_t x, const size_t y);

    const size_t width;
    const size_t height;
    std::vector<state> array;
  } bitmap;
};

#endif // BITMAP_H