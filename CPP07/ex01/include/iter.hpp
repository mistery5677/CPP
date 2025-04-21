#pragma once

// X -> address of an array;
// Y -> Lenght of the array;
// U -> Function to use in each value of the array

template <typename X, typename Y, typename Func> void iter(X *arr, Y lenght, Func func){
    if (!arr)
        return ;
    for (int i = 0; arr[i] && i < lenght; i++)
        func(arr[i]);
}