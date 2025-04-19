#include "include/Serializer.hpp"
#include <iostream>
// #include <cstdint> c++11
#include <stdint.h>


int main() {
    Data originalData = {42, "TEST"};
    
    Data* ptr = &originalData;

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "\033[1;32m";
    std:: cout << "Checking raw value: ";
    std::cout << "\033[1;0m";
    std::cout << raw << std::endl;

    Data* recoveredPtr = Serializer::deserialize(raw);
    if (ptr == recoveredPtr) {
        std::cout << "Success! Pointers match.\n";
        std::cout << "Recovered Data: id = " << recoveredPtr->name
                  << ", name = " << recoveredPtr->name << "\n";
    } else {
        std::cout << "Error! Pointers do not match.\n";
    }

    std::cout << "\nChanging raw value\n" << std::endl;

    raw = 1902;
    Data* recoveredPtr2 = Serializer::deserialize(raw);
    if (ptr == recoveredPtr2) {
        std::cout << "Success! Pointers match.\n";
        std::cout << "Recovered Data: id = " << recoveredPtr->name
                  << ", name = " << recoveredPtr->name << "\n";
    } else {
        std::cout << "Error! Pointers do not match.\n";
    }

    return 0;
}