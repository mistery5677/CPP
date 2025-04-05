#pragma once
#include "Animal.hpp"

class Cat: public Animal{
    private:
        std::string _catType;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &src);
        ~Cat();

        void makeSound() const;
        std::string getType() const;
};