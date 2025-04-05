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

    std::cout << "\nTesting diferent types!!\n" << std::endl;

    const Animal* doberman = new Dog("Doberman");
    const Animal* persian = new Cat("Persian");

    std::cout << "The dog with type " << doberman->getType() << " have the thought: " << doberman->getIdea(0) << std::endl;
    std::cout << "The cat with type " << persian->getType() << " have the thought: " << persian->getIdea(0) << std::endl;

    persian->makeSound();
    doberman->makeSound();

    delete doberman;
    delete persian; 

    std::cout << "\nTesting subject main!!\n" << std::endl;
    
    Animal *animals[10];

    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();

    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        delete animals[i];

    return 0;
}