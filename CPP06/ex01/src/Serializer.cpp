#include "../include/Serializer.hpp"
#include <stdint.h>
// #include <cstdint> c++11

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& copy){}

Serializer& Serializer::operator=(const Serializer& src){}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data *ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t ptr){
    return reinterpret_cast<Data*>(ptr);
}