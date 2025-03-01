#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 4)
    {
        std::fstream myFile;
        std::fstream newFile;

        std::string extension = ".replace";
        std::string fileName = argv[1] + extension;

        myFile.open(argv[1], std::ios::in);
        newFile.open(fileName.c_str(), std::ios::out);
        
        myFile.close();
        newFile.close();
    }
    return 1;
}