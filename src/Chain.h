#ifndef CHAIN_H
#define CHAIN_H

#include <list>
#include <string>

class Chain
{
  public:
    Chain(const size_t line_width, const size_t visible_length);
    Chain(const Chain &) = delete;
    Chain &operator=(const Chain &) = delete;

    void addPoint(const int x, const int y);
    std::string writeInstruction();
    void simplify();
  private:
    const size_t line_width;
    const size_t visible_length;
};

#endif //CHAIN_H