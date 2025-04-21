#pragma once
#include <iostream>

template <typename T> void swap(T &a1, T &a2){
    T temp;
    temp = a1;
    a1 = a2;
    a2 = temp;
}

template <typename U> U& min(U &a1, U &a2){
    
    std::cout << "Min value between: " << a1 << " and " << a2 <<std::endl;
    
    if (a2 <= a1){
        std::cout << "Min value is " << a2 << std::endl;
        return a2;
    }
    std::cout << "Min value is " << a1 << std::endl;
    return a1;
}

template <typename J> J& max(J &a1, J &a2){
    std::cout << "Max value between: " << a1 << " and " << a2 <<std::endl;
    if (a2 >= a1){
        std::cout << "Max value is " << a2 << std::endl;
        return a2;
    }
    std::cout << "Max value is " << a1 << std::endl;
    return a1;
}
