#ifndef INSTRUCTIONREADER_H
#define INSTRUCTIONREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Bitmap.h"
#include "Chain.h"

class InstructionReader
{
public:
  using Point = std::pair<int, int>;
  using Box = std::pair<Point, Point>;
  
  InstructionReader(const std::string &file_name);
  InstructionReader(const InstructionReader &) = delete;
  InstructionReader &operator=(const InstructionReader &) = delete;

  void checkFormat() const;
  Box getBoundingBox() const;
  void setChains(std::vector<Chain> &chains, const size_t width) const;
  void setBitmap(std::unique_ptr<Bitmap> &bitmap, const size_t width) const;
  std::string getPrologue() const;
  std::string getEpilogue() const;

private:
  std::ifstream eps_file;
};

#endif //INSTRUCTIONREADER_H