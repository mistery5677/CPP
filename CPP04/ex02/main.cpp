#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"
#include <iostream>


int main()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    
    cat->makeSound();
    dog->makeSound();
    
    std::cout << "Dog first thought " << dog->getIdea(0) << std::endl;
    std::cout << "Cat first thought " << cat->getIdea(0) << std::endl;

    delete dog;
    delete cat;

    return 0;
}