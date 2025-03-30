#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    private:
        std::string _type;  
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &src);
        ~WrongCat();

        void makeSound() const;
        std::string getType() const;
};