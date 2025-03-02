#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
}

void Harl::debug()
{
    std::cout << "[DEBUG] We are debugging" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO] Do you know that the meaning of everything is 42?" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING] WATCH OUUUT!!!!!!!" << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR] Ohh nooo ... at least is not a seg fault" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"};

    void (Harl::*functions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;    
        }
    }
    
    std::cout << "Unknown level: " << level << std::endl;
}