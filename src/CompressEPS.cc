#include "Converter.h"
#include <iostream>

int main(int argc, char *argv[]) //argv[1] input file, argv[2] output file, argv[3] target width
{
    if(argc != 4)
    {
        std::cerr << ("3 arguments needed: path to input file, path to output file, target width");
        return 1;
    }
    try
    {
        Converter converter(argv[1], atoi(argv[3]));
        converter.compress();
        converter.saveOutputFile(argv[2]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    return 0;
}