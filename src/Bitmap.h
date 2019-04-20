#include <string>
#include "boost/multi_array.hpp"

class Bitmap
{
public:
    Bitmap();
    void fillBitmap(int leftDown, int RightUp);
    std::string writeInstructions();
private:
    Bitmap(const Bitmap&) = delete;
    Bitmap& operator=(const Bitmap&) = delete;
    
    struct bitmapPoint
    {
        char color[2];
        bool fill;
    };
    typedef boost::multi_array<bitmapPoint, 2> bitmap;
}