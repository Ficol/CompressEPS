#include "Chain.h"

Chain::Chain(const double line_width, const double visible_length) : line_width(line_width), visible_length(visible_length)
{
}

void Chain::addPoint(const Point point)
{
    chain.push_back(point);
}

void Chain::writeInstructions(std::string &chain_instruction) const
{
    chain_instruction = "newpath\n";
    chain_instruction.append(std::to_string(chain.begin()->first) + " ");
    chain_instruction.append(std::to_string(chain.begin()->second) + " m\n");
    for(auto i = ++chain.begin(); i != chain.end(); ++i)
    {
        chain_instruction.append(std::to_string(i->first - (--i)->first) + " ");
        chain_instruction.append(std::to_string(i->second - (--i)->second) + " l\n");
    }
    chain_instruction.append(std::to_string(line_width) + "setlinewidth\nstroke\n");
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
        else ++i;
    }
}

double Chain::measureSegment(const Point a, const Point b)
{
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}