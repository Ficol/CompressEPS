#ifndef CONVERTER_H
#define CONVERTER_H

#include <memory>
#include <vector>
#include <fstream>

#include "InstructionInterpreter.h"
#include "Bitmap.h"
#include "Chain.h"

class Converter
{
public:
  Converter(const std::string &input_file, const int target_width);
  Converter(const Converter &) = delete;
  Converter &operator=(const Converter &) = delete;

  void compress();
  void saveOutputFile(const std::string &output_file);

private:
  InstructionInterpreter instruction_interpreter;
  std::vector<Chain> chains;
  std::unique_ptr<Bitmap> bitmap;
  std::ofstream output_file;
};

#endif // CONVERTER_H