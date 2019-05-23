#ifndef CHAIN_H
#define CHAIN_H

#include <list>
#include <string>
#include <utility>
#include <cmath>

class Chain
{
public:
  using Point = std::pair<double, double>;

  Chain(const double line_width, const double visible_length);
  Chain(const Chain &) = delete;
  Chain &operator=(const Chain &) = delete;

  void addPoint(const Point point);
  std::string writeInstructions() const;
  void simplify();

private:
  std::list<Point> chain;
  const int line_width;
  const int visible_length;

  double measureSegment(const Point a, const Point b);
  std::string writePointInstruction(const Point a);
};

#endif // CHAIN_H