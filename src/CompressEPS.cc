#include "Converter.h"
#include <iostream>

int main(int argc, char *argv[]) //argv[1] input file, argv[2] output file, argv[3] target width
{
    if (argc != 4)
    {
        std::cerr << ("3 arguments needed: path to input file, path to output file, target width\n");
        return 1;
    }
    if (atoi(argv[3]) <= 0)
    {
        std::cerr << ("illegal target width\n");
        return 1;
    }
    try
    {
        Converter converter(argv[1], atoi(argv[3]));
        converter.compress();
        converter.saveOutputFile(argv[2]);
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "too big target width to compress\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}