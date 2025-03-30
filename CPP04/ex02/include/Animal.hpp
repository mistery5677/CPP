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

        virtual void makeSound() const;
        virtual std::string getType() const;
        virtual std::string getIdea(int index) const;
};