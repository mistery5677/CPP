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
        ~Span();

        long     shortestSpan();
        long     longestSpan();
        void    addNumber(int number);
        void    getNumbers();
};