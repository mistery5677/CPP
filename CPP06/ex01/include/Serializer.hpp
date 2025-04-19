#pragma once
// #include <cstdint> c++11
#include <stdint.h>
#include <string>

typedef struct Data{
    int number;
    std::string name;
}   Data;

class Serializer{
    private:
    
    public:
        static uintptr_t serialize(Data *ptr); // It takes a pointer and converts it to the unsigned integer type uintptr_t.
        static Data* deserialize(uintptr_t raw); // It takes an unsigned integer parameter and converts it to a pointer to Data.
};