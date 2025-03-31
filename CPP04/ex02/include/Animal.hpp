#pragma once
#include <string>
#include "Brain.hpp"

class Animal{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal &operator=(const Animal &src);
        virtual ~Animal();

        virtual void makeSound() const = 0;
        virtual std::string getType() const = 0;
        virtual std::string getIdea(int index) const = 0;
};