#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
    private:
        std::string _dogType;  
        Brain *_dogBrain;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &copy);
        Dog &operator=(const Dog &src);
        ~Dog();

        void makeSound() const;
        std::string getType() const;
        std::string getIdea(int index) const;
};