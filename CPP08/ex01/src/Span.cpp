#include "../include/Span.hpp"
#include <iostream> // NULL definition
#include <algorithm>

// template <typename N>
Span::Span(){
    _container = NULL;
    _size = 0;
}

// template <typename N>
Span::Span(unsigned int n){
    _container = new int[n]();
    _size = n;
}

Span::~Span(){
    delete[] _container;
}

// template <typename N>
void Span::addNumber(int number){
    unsigned int i = 0;

    for (unsigned int x = i; x < _size && _container[x]; x++){
        
        i++;
        continue;
    }
    if (i == _size)
        throw std::runtime_error("Container is full, you can't add more numbers\n");
    _container[i] = number;
} 

void Span::getNumbers(){
    for (unsigned int i = 0; i < this->_size && this->_container[i]; i++)
        std::cout << "Container[" << i << "] = " << this->_container[i] << std::endl;
}

long Span::shortestSpan(){
    if (this->_size <= 1)
        throw std::runtime_error("Not enough numbers inside the container\n");

    int* copy = new int[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
        copy[i] = this->_container[i];
    
    //SORT CONTAINER;
    std::sort(copy, copy + this->_size);

    //Choose the short combination
    long shortNumber = copy[1] - copy[0];
    if (shortNumber < 0)
        shortNumber *= -1;
    for (unsigned int i = 1; i < this->_size; i++){
        long result = copy[i] - copy[i - 1];
    
        if (result < shortNumber)
            shortNumber = result;
    }
    delete[] copy;
    return shortNumber;
}

long Span::longestSpan(){
    if (this->_size <= 1)
        throw std::runtime_error("Not enough numbers inside the container\n");

    int* copy = new int[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
        copy[i] = this->_container[i];
    
    //SORT CONTAINER;
    std::sort(copy, copy + this->_size);
    
    long longestDistance = copy[this->_size -1] - copy[0];
    delete[] copy;
    
    return longestDistance;
}