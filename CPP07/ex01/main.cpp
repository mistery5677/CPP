/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:46:32 by mistery576        #+#    #+#             */
/*   Updated: 2025/04/23 21:46:33 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/iter.hpp"
#include <iostream>

template <typename T>
void iterate(T &i){
    i++;
}

int main(){
    int arr[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    std::cout << "\033[1;31m";
    std::cout << "*******TESTING ARRAY*******\n" << std::endl;
    std::cout << "\033[1;0m";

    std::cout << "\033[1;32m";
    std::cout << "Before iterate" << std::endl;
    std::cout << "\033[1;0m";
    for (int i = 0; i < 3; i++)
        std::cout << "Arr[" << i << "]: " << arr[i] << std::endl;
    ::iter(arr, 3, iterate<int>);

    std::cout << "\033[1;32m";
    std::cout << "\nAfter iterate" << std::endl;
    std::cout << "\033[1;0m";
    for (int i = 0; i < 3; i++)
        std::cout << "Arr[" << i << "]: " << arr[i] << std::endl;

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING STRING*******\n" << std::endl;
    std::cout << "\033[1;0m";
    
    char str[11] = "GDKKVNQKC";

    std::cout << "\033[1;32m";
    std::cout << "Before iterate" << std::endl;
    std::cout << "\033[1;0m";
    for (int i = 0; i < 9; i++)
        std::cout << "Str[" << i << "]: " << str[i] << std::endl;
    ::iter(str, 11, iterate<char>);

    std::cout << "\033[1;32m";
    std::cout << "\nAfter iterate" << std::endl;
    std::cout << "\033[1;0m";
    for (int i = 0; i < 9; i++)
        std::cout << "Str[" << i << "]: " << str[i] << std::endl;

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING NULL*******" << std::endl;
    std::cout << "\033[1;0m";

    char *test = NULL;
    ::iter(test, 10, iterate<char>);
    std::cout << "\033[1;32m";
    std::cout << "\nNo crashed ✅" << std::endl;
    std::cout << "\033[1;0m";
}