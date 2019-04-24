#ifndef CHAIN_H
#define CHAIN_H

#include <list>
#include <string>

class Chain
{
  public:
    Chain(const size_t line_width);
    Chain(const Chain &) = delete;
    Chain &operator=(const Chain &) = delete;

    void addPoint(const int x, const int y);
    std::string writeInstruction();
    void simplify();
  private:
    typedef std::pair<int, int> Point;
    std::list<Point> chain;
    const size_t line_width;
    static size_t visible_length;
    friend class Converter;
};

#endif //CHAIN_H