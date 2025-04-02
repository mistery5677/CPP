#include "../include/ICharacter.hpp"
#include <iostream>

ICharacter::~Icharacter(){
    std::cout << "ICharacter got destroyed" << std::endl;
}