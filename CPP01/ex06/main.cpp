#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    switch (argc)
    {
        case 1:
        {
            std::cout << "Nothing for Harl to complain" << std::endl;
            break;
        }
        case 2:
        {
            Harl harl;

            harl.complain(argv[1]);
            break;
        }
        default:
        {
            std::cout << "To many things for Harl to complain" << std::endl;
            break;
        }
    }
}