#pragma once
#include <string>

class WrongAnimal{
    private:
        std::string _type;  
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &src);
        virtual ~WrongAnimal();

        virtual void makeSound() const;
        virtual std::string getType() const;
};