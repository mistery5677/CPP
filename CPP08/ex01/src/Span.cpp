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

unsigned int Span::shortestSpan(){
    int shortSpan = 0;

    if (this->_size <= 1)
        throw std::runtime_error("Not enough numbers inside the container\n");

    int* copy = new int(this->_size);
    for (int i = 0; i < this->_size; i++)
        copy[i] = this->_container[i];
    
    //SORT CONTAINER;
    std::sort(copy, copy + this->_size);

    //Choose the short combination
    unsigned int shortNumber = copy[1] - copy[0];
    for (int i = 1; i < this->_size; i++){
        unsigned int result = copy[i] - copy[i - 1];

        if (result < shortNumber)
            shortNumber = result;
    }
    delete[] copy;
    return shortNumber;
}

unsigned int Span::longestSpan(){
    if (this->_size <= 1)
        throw std::runtime_error("Not enough numbers inside the container\n");

    int* copy = new int(this->_size);
    for (int i = 0; i < this->_size; i++)
        copy[i] = this->_container[i];
    
    //SORT CONTAINER;
    std::sort(copy, copy + this->_size);
    return copy[this->_size - 1] - copy[0]; 
}