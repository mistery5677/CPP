#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl << "We are debugging" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl << "Do you know that the meaning of everything is 42?" << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl << "WATCH OUUUT!!!!!!!" << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl << "Ohh nooo ... at least is not a seg fault" << std::endl;
}

void Harl::complain(std::string level)
{
    int i;

    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"};

    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            break;
    }
    switch (i)
    {
        case 0:
            debug();
            info();
            warning();
            error();
            break;

        case 1:
            info();
            warning();
            error();
            break;

        case 2:
            warning();
            error();
            break;

        case 3:
        {
            error();
            break;
        }
        case 4:
        {
            std::cout << "[Probably complaining about insignificant problems]" << std::endl;
            break;
        }
    }
}