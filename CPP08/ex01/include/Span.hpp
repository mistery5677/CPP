#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
private:
    int*            _container;       // Dynamic array
    unsigned int    _size;            // size
    unsigned int    _inserted;        // Inserted numbers

public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void    addNumber(int number);
	void	addMultipleNumbers(int min, int max);
    long    shortestSpan();
    long    longestSpan();
    void    getNumbers(); // Debug
};
