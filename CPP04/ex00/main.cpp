#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include <iostream>


int main()
{

    std::cout << "\nTesting Subject!!\n" << std::endl;


    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl;
    std::cout << "Checking type: " << cat->getType() << std::endl;
    std::cout << "Checking type: " << dog->getType() << std::endl;
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();


    delete meta;
    delete cat;
    delete dog;  

    std::cout << "\nTesting diferent types!!\n" << std::endl;

    const Animal* doberman = new Dog("Doberman");
    const Animal* persian = new Cat("Persian");

    std::cout << "Checking type: " << doberman->getType() << " " << std::endl;
    std::cout << "Checking type: " << persian->getType() << " " << std::endl;

    persian->makeSound();
    doberman->makeSound();

    std::cout << "\nTesting copy constructor!!\n" << std::endl;

    Dog test("test");
    const Animal* testClone = new Dog(test);

    std::cout << "Checking type of doberman clone: " << testClone->getType() << std::endl;

    std::cout << "\nTesting wrong animals!!\n" << std::endl;
    
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); 
    meta2->makeSound();

    
    delete testClone;
    delete doberman;
    delete persian;  
    delete meta2;
    delete i;

    return 0;
}