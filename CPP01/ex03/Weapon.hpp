#pragma once
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    const std::string& getType() const;
    void setType(std::string newType);

};