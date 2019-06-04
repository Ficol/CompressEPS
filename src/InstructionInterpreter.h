#ifndef INSTRUCTIONINTERPRETER_H
#define INSTRUCTIONINTERPRETER_H

#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <memory>
#include <utility>

#include "Bitmap.h"
#include "Chain.h"

class InstructionInterpreter
{
public:
  using Point = std::pair<double, double>;
  using Box = std::pair<Point, Point>;

  InstructionInterpreter(const std::string &file_name);
  ~InstructionInterpreter();
  InstructionInterpreter(const InstructionInterpreter &) = delete;
  InstructionInterpreter &operator=(const InstructionInterpreter &) = delete;

  void checkFormat();
  void setChains(std::vector<Chain> &chains, const size_t target_width);
  void setBitmap(std::unique_ptr<Bitmap> &bitmap, const size_t target_width);
  void setPrologue(std::string &prologue);
  void setEpilogue(std::string &epilogue);

private:
  Box getBoundingBox();
  std::ifstream eps_file;
};

#endif // INSTRUCTIONINTERPRETER_H