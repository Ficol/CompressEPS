#ifndef INSTRUCTIONINTERPRETER_H
#define INSTRUCTIONINTERPRETER_H

#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

#include "Bitmap.h"
#include "Chain.h"

class InstructionInterpreter
{
public:
  using Point = std::pair<int, int>;
  using Box = std::pair<Point, Point>;

  InstructionInterpreter(const std::string &file_name);
  InstructionInterpreter(const InstructionInterpreter &) = delete;
  InstructionInterpreter &operator=(const InstructionInterpreter &) = delete;

  void checkFormat() const;
  void setChains(std::vector<Chain> &chains, const int target_width) const;
  void setBitmap(std::unique_ptr<Bitmap> &bitmap, const int target_width) const;
  std::string getPrologue() const;
  std::string getEpilogue() const;

private:
  Box getBoundingBox() const;
  /**/

  std::ifstream eps_file;
};

#endif // INSTRUCTIONINTERPRETER_H