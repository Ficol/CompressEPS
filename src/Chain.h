#ifndef CHAIN_H
#define CHAIN_H

#include <list>
#include <string>
#include <utility>

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
};

#endif // CHAIN_H