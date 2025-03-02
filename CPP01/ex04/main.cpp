#include <fstream>
#include <iostream>
#include <string>
#include "Files.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string extension = ".replace";
        std::string outfile = argv[1] + extension;
        Files files(argv[1], outfile, argv[2], argv[3]);

        files.readFile();
        files.~Files();
    }
    else
        std::cout << "Expeted input: <file name> <target> <replace>" << std::endl;
    return 1;
}