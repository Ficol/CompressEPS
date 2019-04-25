#include "Converter.h"
#include <iostream>

int main(int argc, char *argv[]) //argv[1] wejsciowy plik, argv[2] wyjsciowy plik, argv[3] docelowa szerokosc obrazu
{
    try
    {
        Converter converter(argv[1]);
        converter.compress();
        converter.createOutputFile();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}