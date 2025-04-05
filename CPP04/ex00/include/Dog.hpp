#pragma once
#include "Animal.hpp"

class Dog: public Animal{
    private:
        std::string _dogType;  
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &copy);
        Dog &operator=(const Dog &src);
        ~Dog();

        void makeSound() const;
        std::string getType() const;
};