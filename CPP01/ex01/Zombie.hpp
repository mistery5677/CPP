#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>

class Zombie
{
private:
    std::string name; 
public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce(void);
};

#endif