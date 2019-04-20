#include "InstructionReader"

class CompresserEps
{
public:
    CompresserEps(std::string inputFile, std::string outputFile, int width, int height);
    void Compress();
    void createOutputFile();
private:
    CompresserEps() = delete;
    CompresserEps(const CompresserEps&) = delete;
    CompresserEps& operator=(const CompresserEps&) = delete;
    
    InstructionReader instructionReader;
    std::vector<Chain> chains;
    Bitmap bitmap;
    std::ofstream newEpsFile;
}