#include "../include/Array.hpp"

template<typename T>
Array<T>::Array(): _size(0){
    _data = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n): _size(n){
    _data = new T[n]();
}

template<typename T>
Array<T>::Array(const Array<T>& copy){
    this->_data = new T[copy.size()]();
    this->_size = copy._size;
    for(int i = 0; copy._data[i]; i++)
        this->_data[i] = copy._data[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& src){
    if (this->_data != NULL)
        delete[] this->_data;

    this->_data = new T[src.size()]();
    this->_size = src._size;
    for(int i = 0; src._data[i]; i++)
        this->_data[i] = src._data[i];
    return this;
}

template<typename T>
T& Array<T>::operator[](int index){
    return _data[index];
}

template<typename T>
Array<T>::~Array(){
    delete[] _data;
}

template<typename T>
int Array<T>::size() const{
    return _size;
}

template<typename T>
void Array<T>::printData(){
    for (int i = 0; this->_data[i]; i++)
        std::cout << "Data[" << i << "]: " << _data[i] << std::endl;
}