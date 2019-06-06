#ifndef BITMAP_H
#define BITMAP_H

/**
 * @file Bitmap.h
 * @author Jakub Ficek
 * @brief Class stores rectangles from file and compresses them.
 */

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
  /**
   * @brief To represent rectangle as lower-left and upper-right corner
   */
  using Box = std::pair<Point, Point>;
  /**
   * @brief Construct a new Bitmap object
   * length of one point in bitmap equals visible_length
   */
  Bitmap(const Box bounding_box, double visible_length);
  Bitmap(const Bitmap &) = delete;
  Bitmap &operator=(const Bitmap &) = delete;
  bool operator==(const Bitmap &) const;
  bool operator!=(const Bitmap &) const;
  /**
    * @brief states of points in bitmap:
    */
  enum state
  {
    empty,
    filled,
    written
  };
  /**
   * @brief Adds rectangle to bitmap
   * 
   * @param rectangle Rectangle to be added
   */
  void addRectangle(const Box rectangle);
  /**
   * @brief Simplifies bitmap
   * 
   */
  void simplify();
  /**
   * @brief Writes instructions based on filled bitmap
   * 
   * @param bitmap_instruction String in which instructions are saved
   */
  void writeInstructions(std::string &bitmap_instruction);

private:
  /**
    * @brief Deletes rectangles 1x1 in bitmap,
    * part of simplify method
    * 
    */
  void deleteSmallRectangles();
  /**
   * @brief Measures size of maximal possible rectangle that can be created
   * 
   * @param x 
   * @param y 
   * @return size_t 
   */
  size_t measureRectangleWidth(size_t x, size_t y);
  size_t measureRectangleHeight(size_t x, size_t y, size_t width);
  void setRectangleWritten(size_t x, size_t y, size_t width, size_t height);

  const Box bounding_box;
  const double visible_length;
  class Array2D
  {
  public:
    Array2D(const double width, const double height);

    enum state &index(const size_t x, const size_t y);
    enum state get(const size_t x, const size_t y) const;

    const size_t width;
    const size_t height;
    std::vector<state> array;
  } bitmap;
};

#endif // BITMAP_H