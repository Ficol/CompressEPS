#include <list>

class Chain
{
public:
    Chain();
    std::string writeInstruction();
    void simplify();
private:
    Chain() = delete;
    Chain(const Chain&) = delete;
    Chain& operator=(const Chain&) = delete;
    
    typedef std::pair<int, int> point;
    std::list<point> chain;

}