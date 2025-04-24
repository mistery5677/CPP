#pragma once
#include <exception>

// template <typename N>
class Span{
    private:
        int*            _container;
        unsigned int    _size;
    public:
        Span();
        Span(unsigned int n);

        unsigned int     shortestSpan();
        unsigned int     longestSpan();
        void    addNumber(int number);
        void    getNumbers();
};