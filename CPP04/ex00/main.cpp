#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include <iostream>


int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();


    delete meta;
    delete cat;
    delete dog;  

    std::cout << "\nTesting diferent types!!\n" << std::endl;

    const Animal* doberman = new Dog("Doberman");
    const Animal* persian = new Cat("Persian");

    std::cout << doberman->getType() << " " << std::endl;
    std::cout << persian->getType() << " " << std::endl;

    persian->makeSound();
    doberman->makeSound();

    delete doberman;
    delete persian;  

    std::cout << "\nTesting wrong animals!!\n" << std::endl;

    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << i->getType() << " " << std::endl;

    i->makeSound();  // Isso imprimirá "WrongAnimal --> Some generic wrong sound"
    meta2->makeSound();

    delete meta2;
    delete i;

    return 0;
}