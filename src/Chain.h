#ifndef CHAIN_H
#define CHAIN_H

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

  Chain(const double visible_length);
  Chain(const Chain &chain);
  Chain &operator=(const Chain &);
  bool operator==(const Chain &) const;
  bool operator!=(const Chain &) const;

  void addPoint(const Point point);
  void writeInstructions(std::string &chain_instruction) const;
  void simplify();
  size_t getPointAmount();
  void clear();
  void setLineWidth(size_t _line_width);

private:
  std::list<Point> chain;
  size_t line_width;
  double visible_length;

  double measureSegment(const Point a, const Point b);
  std::string writePointInstruction(const Point a);
};

#endif // CHAIN_H