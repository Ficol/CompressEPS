#ifndef INSTRUCTIONINTERPRETER_H
#define INSTRUCTIONINTERPRETER_H
/**
 * @file InstructionInterpreter.h
 * @author Jakub Ficek
 * @brief Reads instructions from input file and converts them to objects.\n
 * Verifies input file format.
 */
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
  /**
   * @brief Opens input file
   * @param file_name Input eps file
   */
  InstructionInterpreter(const std::string &file_name);
  /**
   * @brief Closes input file
   */
  ~InstructionInterpreter();
  InstructionInterpreter(const InstructionInterpreter &) = delete;
  InstructionInterpreter &operator=(const InstructionInterpreter &) = delete;
  /**
   * @brief Checks corectness of instructions in input file 
   */
  void checkFormat();
  /**
   * @brief Finds specific instructions and add chain objects to vector of chains
   */
  void setChains(std::vector<Chain> &chains, const size_t target_width);
  /**
   * @brief Finds specific instructions and add rectangles to Bitmap Object
   */
  void setBitmap(std::unique_ptr<Bitmap> &bitmap, const size_t target_width);
  /**
   * @brief Set Prologue of output file
   */
  void setPrologue(std::string &prologue);
  /**
   * @brief Set Epilogue of output file
   */
  void setEpilogue(std::string &epilogue);

private:
  Box getBoundingBox();
  std::ifstream eps_file;
};

#endif // INSTRUCTIONINTERPRETER_H