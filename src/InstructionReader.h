#ifndef INSTRUCTIONREADER_H
#define INSTRUCTIONREADER_H

#include <fstream>
#include <string>
#include <vector>
#include "Bitmap.h"
#include "Chain.h"

class InstructionReader
{
  public:
    InstructionReader(const std::string &file_name);
    InstructionReader(const InstructionReader &) = delete;
    InstructionReader &operator=(const InstructionReader &) = delete;
    ~InstructionReader();
    
    void checkFormat() const;
    typedef std::pair<int, int> Point;
    typedef std::pair<Point, Point> Box;
    Box getBoundingBox() const;
    void addChains(std::vector<Chain> &chains) const;
    void addRectangles(Bitmap &bitmap) const;

  private:
    std::ifstream eps_file;
};

#endif //INSTRUCTIONREADER_H