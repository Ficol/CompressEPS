#include "InstructionInterpreter.h"

InstructionInterpreter::InstructionInterpreter(const std::string &file_name)
{
    eps_file.open(file_name);
    if (!eps_file.is_open())
        throw std::ios_base::failure("Can't open input file");
}

InstructionInterpreter::~InstructionInterpreter()
{
    eps_file.close();
}

void InstructionInterpreter::checkFormat()
{
    std::string line;
    bool format = false;
    while (std::getline(eps_file, line))
    {
        if (line.find("%%BoundingBox:") != std::string::npos)
        {
            format = true;
            break;
        }
    }
    if (!format)
        throw std::ios_base::failure("Wrong format");
    eps_file.clear();
    eps_file.seekg(0, std::ios::beg);
    format = false;
    while (std::getline(eps_file, line))
    {
        if (line.find("%!PS-Adobe-3.0") != std::string::npos)
        {
            format = true;
            break;
        }
    }
    if (!format)
        throw std::ios_base::failure("Wrong format");
}

InstructionInterpreter::Box InstructionInterpreter::getBoundingBox()
{
    eps_file.clear();
    eps_file.seekg(0, std::ios::beg);
    std::string line;
    std::stringstream line_stream;
    while (std::getline(eps_file, line))
    {
        if (line.find("%%BoundingBox:") != std::string::npos)
        {
            line_stream << line;
            break;
        }
    }
    Box bounding_box;
    line_stream >> line >> bounding_box.first.first >> bounding_box.first.second >> bounding_box.second.first >> bounding_box.second.second;
    bounding_box.second.first += bounding_box.first.first;
    bounding_box.second.second += bounding_box.first.second;
    return bounding_box;
}

void InstructionInterpreter::setChains(std::vector<Chain> &chains, const size_t target_width)
{
    Box bounding_box = getBoundingBox();
    eps_file.clear();
    eps_file.seekg(0, std::ios::beg);
    std::string line;
    while (std::getline(eps_file, line))
    {
        if (line == "newpath")
        {
            Chain new_chain(0.01 * (bounding_box.second.first - bounding_box.first.first) / static_cast<double>(target_width));
            Point previous_point = std::make_pair(0, 0);
            while (line.find("stroke") == std::string::npos)
            {
                Point new_point;
                std::stringstream line_stream;
                std::string command;
                std::getline(eps_file, line);
                line_stream << line;
                if (line.find("setlinewidth") != std::string::npos)
                {
                    size_t tmp;
                    line_stream >> tmp;
                    new_chain.setLineWidth(tmp);
                }
                line_stream >> new_point.first >> new_point.second >> command;
                if (command == "l" || command == "rlineto")
                {
                    new_point.first += previous_point.first;
                    new_point.second += previous_point.second;
                    new_chain.addPoint(new_point);
                }
                else if (command == "lineto" || ((command == "m" || command == "move") && new_chain.getPointAmount() == 0))
                    new_chain.addPoint(new_point);
                else if (command == "m" || command == "move")
                {
                    chains.push_back(new_chain);
                    new_chain.clear();
                    new_chain.addPoint(new_point);
                }
                previous_point = new_point;
            }
            chains.push_back(new_chain);
        }
    }
}

void InstructionInterpreter::setBitmap(std::unique_ptr<Bitmap> &bitmap, const size_t target_width)
{
    Box bounding_box = getBoundingBox();
    bitmap = std::make_unique<Bitmap>(bounding_box, 0.01 * (bounding_box.second.first - bounding_box.first.first) / static_cast<double>(target_width));
    eps_file.clear();
    eps_file.seekg(0, std::ios::beg);
    std::string line;
    while (std::getline(eps_file, line))
    {
        if(line.find(" r p2"))
        {
            Box new_rectangle;
            std::stringstream line_stream;
            line_stream << line;
            line_stream >> new_rectangle.first.first >> new_rectangle.first.second >> new_rectangle.second.first >> new_rectangle.second.second;
            new_rectangle.second.first += new_rectangle.first.first;
            new_rectangle.second.second += new_rectangle.first.second;
            bitmap->addRectangle(new_rectangle);
        }
    }
}

void InstructionInterpreter::setPrologue(std::string &prologue)
{
    Box box = getBoundingBox();
    prologue = "%%!PS-Adobe-3.0 EPSF-3.0\n"
               "%%Title: R Graphics Output\n"
               "%%Creator: R Software\n"
               "%%Pages: (atend)\n"
               "%%BoundingBox: ";
    prologue += std::to_string(box.first.first) + " " +
                std::to_string(box.first.second) + " " +
                std::to_string(box.second.first) + " " +
                std::to_string(box.second.second) + "\n";
    prologue += "/m   { moveto } bind def\n"
                "/l  { rlineto } bind def\n"
                "/gs  { gsave } bind def\n"
                "/bg { 0 0 0 srgb } def\n"
                "/srgb { setcolor } bind def\n"
                "/r   { 4 2 roll moveto 1 copy 3 -1 roll exch 0 exch rlineto 0 rlineto -1 mul 0 exch rlineto closepath } bind def\n"
                "/p2  { gsave bg fill grestore newpath } bind def\n";
    eps_file.clear();
    eps_file.seekg(0, std::ios::beg);
    std::string line;
}

void InstructionInterpreter::setEpilogue(std::string &epilogue)
{
    epilogue = "showpage";
}