#include <string>
#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *brain_ptr = &brain;
    std::string &brain_ref = brain;

    std::cout << "Memory address string: " << &brain
            << "\nMemory address string_ptr: " << brain_ptr
            << "\nMemory address string_ref: " << &brain_ref << std::endl;

    std::cout << "Value string: " << brain
        << "\nValue string_ptr: " << *brain_ptr
        << "\nValue string_ref: " << brain_ref << std::endl;
}