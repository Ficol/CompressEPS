#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <utility>
#include <vector>
#include <cmath>

class Bitmap
{
public:
  using Point = std::pair<double, double>;
  using Box = std::pair<Point, Point>;
  Bitmap(const Box bounding_box, double visible_length);
  Bitmap(const Bitmap &) = delete;
  Bitmap &operator=(const Bitmap &) = delete;
  enum state {empty, filled, written};
  void addRectangle(const Box rectangle);
  void simplify();
  std::string writeInstructions() const;

private:
  void mergeCloseRectangles();
  void deleteSmallRectangles();
  bool isRectangleSmall(int x, int y);
  void deleteRectangle(int x, int y);

  const Box bounding_box;
  const int visible_length;
  class Array2D
  {
  public:
    Array2D(const double width, const double height);

    state &index(const int x, const int y);

    const int width;
    const int height;
    std::vector<state> array;
  } bitmap;
};

#endif // BITMAP_H