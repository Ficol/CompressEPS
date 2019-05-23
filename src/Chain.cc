#include "Chain.h"

Chain::Chain(const double line_width, const double visible_length) : line_width(line_width), visible_length(visible_length)
{
}

void Chain::addPoint(const Point point)
{
    chain.push_back(point);
}

std::string Chain::writeInstructions() const
{
    std::string chain_instruction("newpath\n");
    chain_instruction += (chain.begin()->first);
    chain_instruction += (" ");
    chain_instruction += (chain.begin()->second);
    chain_instruction += (" m\n");
    for(auto i = ++chain.begin(); i != chain.end(); ++i)
    {
        chain_instruction += (i->first - (--i)->first);
        chain_instruction +=(" ");
        chain_instruction += (i->second - (--i)->second);
        chain_instruction +=(" ");
        chain_instruction += (" l\n");
    }
    chain_instruction += (line_width);
    chain_instruction += (" setlinewidth\nstroke");
    return chain_instruction;
}

void Chain::simplify()
{
    if(chain.size() <= 2)
        return;
    auto i = ++chain.begin();
    while(i != --chain.end())
    {
        if(measureSegment(*(--i), *i) + measureSegment(*i, *(++i)) - measureSegment(*(--i), *(++i)) < visible_length)
        {
            --i;
            chain.erase(++i);
        }
        ++i;
    }
}

double Chain::measureSegment(const Point a, const Point b)
{
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}