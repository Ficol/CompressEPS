#include "Chain.h"

Chain::Chain(const double visible_length) : visible_length(visible_length)
{
}

Chain::Chain(const Chain &_chain) : line_width(_chain.line_width), visible_length(_chain.visible_length)
{
    chain = _chain.chain;
}

Chain &Chain::operator=(const Chain &_chain)
{
    if (&_chain == this)
        return *this;
    line_width = _chain.line_width;
    visible_length = _chain.visible_length;
    chain = _chain.chain;
    return *this;
}

void Chain::addPoint(const Point point)
{
    chain.push_back(point);
}

void Chain::writeInstructions(std::string &chain_instruction) const
{
    std::ostringstream instruction;
    instruction << std::fixed;
    instruction << std::setprecision(2);
    chain_instruction = "newpath\n";
    instruction << chain.begin()->first << " ";
    instruction << chain.begin()->second << " m\n";
    for (auto i = ++chain.begin(); i != chain.end(); ++i)
    {
        instruction << i->first - std::prev(i)->first << " ";
        instruction << i->second - std::prev(i)->second << " l\n";
    }
    instruction << line_width << " setlinewidth\nstroke\n";
    chain_instruction += instruction.str();
}

void Chain::simplify()
{
    if (chain.size() <= 2)
        return;
    auto i = ++chain.begin();
    bool simplifyEnd = false;
    while (!simplifyEnd)
    {
        simplifyEnd = true;
        while (i != --chain.end())
        {
            if (measureSegment(*(std::prev(i)), *i) + measureSegment(*i, *(std::next(i))) - measureSegment(*(std::prev(i)), *(std::next(i))) < visible_length)
            {
                --i;
                simplifyEnd = false;
                chain.erase(std::next(i));
            }
            ++i;
        }
    }
}

size_t Chain::getPointAmount()
{
    return chain.size();
}

void Chain::clear()
{
    chain.clear();
}

void Chain::setLineWidth(size_t _line_width)
{
    line_width = _line_width;
}

double Chain::measureSegment(const Point a, const Point b)
{
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}