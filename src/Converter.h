#ifndef CONVERTER_H
#define CONVERTER_H

/**
 * @file Converter.h
 * @author Jakub Ficek
 * @brief Controlls classes Bitmap, Chain, InstructionInterpreter.\n
 * Creates compressed output file.
 */

#include <memory>
#include <vector>
#include <fstream>

#include "InstructionInterpreter.h"
#include "Bitmap.h"
#include "Chain.h"

class Converter
{
public:
/**
 * @brief Using instruction_interpreter, opens input eps files and convert instructions to Objects
 * 
 * @param input_file Name of input file
 * @param target_width Target width of image
 */
  Converter(const std::string &input_file, const size_t target_width);
  Converter(const Converter &) = delete;
  Converter &operator=(const Converter &) = delete;
/**
 * @brief Converts objects to create smaller eps file
 */
  void compress();
  /**
   * @brief Creates instructions based on states of objects and creates output file
   * 
   * @param output_file Name of output file
   */
  void saveOutputFile(const std::string &output_file);

private:
  InstructionInterpreter instruction_interpreter;
  std::vector<Chain> chains;
  std::unique_ptr<Bitmap> bitmap;
  std::ofstream output_file;
};

#endif // CONVERTER_H