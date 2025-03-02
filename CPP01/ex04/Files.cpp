#include "Files.hpp"

Files::Files(std::string inFile, std::string outFile, std::string target, std::string replace)
    :target(target),
    replace(replace)
{
    myFile.open(inFile.c_str(), std::ios::in);
    if (myFile.fail())
        return ;
    else
        newFile.open(outFile.c_str(), std::ios::out);
}

Files::~Files()
{
    myFile.close();
    newFile.close();
}

void Files::readFile()
{
    size_t pos1;
    size_t pos2;
    std::string line;

    while (getline(myFile, line))
    {
        pos1 = 0;
        pos2 = line.find(target);
        while (pos2 != std::string::npos)
        {
            newFile << line.substr(pos1, pos2 - pos1) << replace;
            pos1 = pos2 + target.size();
            pos2 = line.find(target, pos1);
        }
        newFile << line.substr(pos1);
        if (!myFile.eof())
            newFile << std::endl;
    }
}