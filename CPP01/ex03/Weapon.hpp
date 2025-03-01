#pragma once
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(std::string newType);
};