#ifndef CHAIN_H
#define CHAIN_H
/**
 * @file Chain.h
 * @author Jakub Ficek
 * @brief  Class stores and simplifies segments from input file
 * 
 */
#include <list>
#include <string>
#include <utility>
#include <cmath>
#include <iterator>
#include <sstream>
#include <iomanip>

class Chain
{
public:
  using Point = std::pair<double, double>;
  /**
   * @brief Construct a new Chain object
   * 
   * @param visible_length Minimal length that can be seen for given target width
   */
  Chain(const double visible_length);
  Chain(const Chain &chain);
  Chain &operator=(const Chain &);
  bool operator==(const Chain &) const;
  bool operator!=(const Chain &) const;
/**
 * @brief Add point at the end of chain
 */
  void addPoint(const Point point);
  /**
   * @brief Writes instruction based on state of chain
   * 
   * @param chain_instruction String in which instructions are saved
   */
  void writeInstructions(std::string &chain_instruction) const;
  /**
   * @brief Simplifies Chain.
   * Deletes points that are close to be collinear.
   */
  void simplify();
  /**
   * @brief Get the Point Amount object
   * 
   * @return Amount of points in chain
   */
  size_t getPointAmount();
  /**
   * @brief Removes all points in chain
   * 
   */
  void clear();
  /**
   * @brief Set the line width of Chain
   */
  void setLineWidth(size_t _line_width);

private:
  std::list<Point> chain;
  size_t line_width;
  double visible_length;

  double measureSegment(const Point a, const Point b);
  std::string writePointInstruction(const Point a);
};

#endif // CHAIN_H