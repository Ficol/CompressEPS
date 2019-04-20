#include <fstream>
#include <string>
#include <vector>
#include "Bitmap.h"
#include "Chain.h"

class InstructionReader
{
public:
    InstructionReader(std::string fileName);
    void checkFormat();
    int setVisibleSize();
    void readChains(std::vector<Chain> &chains);
    void readPoints(Bitmap &bitmap);
private:
    InstructionReader() = delete;
    InstructionReader(const InstructionReader&) = delete;
    InstructionReader& operator=(const InstructionReader&) = delete;

    std::ifstream epsFile;
}