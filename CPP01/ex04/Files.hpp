#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Files
{
private:
    std::fstream myFile;
    std::fstream newFile;
    std::string target;
    std::string replace;
public:
    Files(std::string inFile, std::string outFile, std::string target, std::string replace);
    ~Files();
    void readFile();
};