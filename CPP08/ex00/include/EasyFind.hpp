#pragma once
#include <iostream>
#include <exception>
#include <algorithm> // find
#define ERROR_MSG "Error"

template<typename T> 
typename T::iterator easyFind(T& container, int value){

    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return it;
    throw std::logic_error("No occurrence found");
    // Funciona para alguns containers como vector e deque
    // for (size_t i = 0; i < container.size(); i++){
    //     if (container[i] == value)
    //         return static_cast<int>(i);
    // }
    // return -1;
}