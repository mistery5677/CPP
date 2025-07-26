#include "../include/Span.hpp"

Span::Span() : _container(), _size(0), _inserted(0) {}

Span::Span(unsigned int n) : _size(n), _inserted(0) {
    _container = new int[n];
}

Span::Span(const Span& other) : _size(other._size), _inserted(other._inserted) {
    _container = new int[_size];
    std::copy(other._container, other._container + _inserted, _container);
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        delete[] _container;
        _size = other._size;
        _inserted = other._inserted;
        _container = new int[_size];
        std::copy(other._container, other._container + _inserted, _container);
    }
    return *this;
}

Span::~Span() {
    delete[] _container;
}

void Span::addNumber(int number) {
    if (_inserted >= _size)
        throw std::runtime_error("Container is full, you can't add more numbers");
    _container[_inserted++] = number;
}

void Span::addMultipleNumbers(int min, int max) {
	if (min > max)
		throw std::runtime_error("Min value is higher than max");

	for (int i = 0; min <= max; i++){
		addNumber(min);
		min++;
	}
}

long Span::shortestSpan() {
    if (_inserted < 2)
        throw std::runtime_error("Need at least two numbers to compute a span");

    // Copy and sort the numbers
    int* temp = new int[_inserted];
    std::copy(_container, _container + _inserted, temp);
    std::sort(temp, temp + _inserted);

    long minSpan = LONG_MAX;
    for (unsigned int i = 0; i < _inserted - 1; i++) {
        long span = static_cast<long>(temp[i + 1]) - temp[i];
        if (span < minSpan)
            minSpan = span;
    }

    delete[] temp;
    return minSpan;
}

long Span::longestSpan() {
    if (_inserted < 2)
        throw std::runtime_error("Need at least two numbers to compute a span");

    int min = *std::min_element(_container, _container + _inserted);
    int max = *std::max_element(_container, _container + _inserted);

    return static_cast<long>(max) - min;
}

void Span::getNumbers() {
    std::cout << "Numbers in Span: ";
    for (unsigned int i = 0; i < _inserted; ++i)
        std::cout << _container[i] << " ";
    std::cout << std::endl;
}
