/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:46:48 by mistery576        #+#    #+#             */
/*   Updated: 2025/04/23 21:46:50 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Array.hpp"
#include "src/Array.tpp"
#include <cstdlib>


int main(){
    
    std::cout << "\033[1;31m";
    std::cout << "*******TESTING SUBJECT*******\n" << std::endl;
    std::cout << "\033[1;0m";

    int *a = new int();
    std::cout << *a << std::endl;
    int *b = new int();
    std::cout << *b << std::endl;

    delete a;
    delete b;
    
    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING COPY AND ASSIGNMENT OPERATOR*******\n" << std::endl;
    std::cout << "\033[1;0m";

    Array<int> integer(2);
    integer[0] = 10;
    integer[1] = 20;

    std::cout << "\033[1;32m";
    std::cout << "Printing integer var values\n" << std::endl;
    std::cout << "\033[1;0m";
    integer.printData();

    std::cout << "\033[1;33m";
    std::cout << "\nCopying integer array to integer2" << std::endl;
    std::cout << "\033[1;0m";

    Array<int> integer2(integer);

    std::cout << "\033[1;32m";
    std::cout << "\nPrinting integer2 var values\n" << std::endl;
    std::cout << "\033[1;0m";
    integer2.printData();

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING CHANGING VALUES*******\n" << std::endl;
    std::cout << "\033[1;0m";

    integer[0] = 99;

    std::cout << "\033[1;32m";
    std::cout << "Printing integer var values\n" << std::endl;
    std::cout << "\033[1;0m";

    integer.printData();

    std::cout << "\033[1;32m";
    std::cout << "\nPrinting integer2 var values\n" << std::endl;
    std::cout << "\033[1;0m";

    integer2.printData();
}

// Main subject
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
    
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }