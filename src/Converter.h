#ifndef CONVERTER_H
#define CONVERTER_H

#include <memory>
#include <vector>
#include <fstream>
#include "InstructionReader.h"

class Converter
{
  public:
    Converter(const std::string &input_file, const size_t width = 1000, const size_t height = 1000);
    Converter(const Converter &) = delete;
    Converter &operator=(const Converter &) = delete;

    void compress();
    void createOutputFile(const std::string &output_file = "output.eps");

  private:
    InstructionReader instruction_reader;
    std::vector<Chain> chains;
    std::unique_ptr<Bitmap> bitmap;
    std::ofstream new_eps_file;
};

#endif //CONVERTER_H