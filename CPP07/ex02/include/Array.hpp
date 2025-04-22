#pragma once

template<typename T> class Array{
    private:
        T       *_data;
        int     _size;
        
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(const Array& src);
        T& operator[](int index);
        ~Array();
        
        int         size() const;
        void        printData();
};

#include "../src/Array.tpp"