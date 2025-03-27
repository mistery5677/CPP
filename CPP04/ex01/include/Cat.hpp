#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
    private:
        std::string _type;
        Brain *_brain;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &src);
        ~Cat();

        void makeSound() const;
        std::string getType() const;
        std::string getIdea(int index) const;
};