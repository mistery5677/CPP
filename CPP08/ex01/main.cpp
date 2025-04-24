#include "include/Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
    std::cout << "\033[1;31m";
    std::cout << "*******TESTING MY CONTAINER*******\n" << std::endl;
    std::cout << "\033[1;0m";

    std::cout << "\033[1;32m";
    std::cout << "\n*******TESTING SUBJECT*******\n" << std::endl;
    std::cout << "\033[1;0m";

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\033[1;32m";
    std::cout << "\n*******TESTING ADD ANOTHER NUMBER TO FULL CONTAINER*******\n" << std::endl;
    std::cout << "\033[1;0m";

    try{
        sp.addNumber(11);
    } catch(const std::exception& msg){
        std::cout << msg.what() << std::endl;
    }
    sp.getNumbers();

    std::cout << "\033[1;32m";
    std::cout << "\n*******TESTING 10000 numbers*******\n" << std::endl;
    std::cout << "\033[1;0m";

    Span sp2 = Span(100000);
    srand(time(0));
    for (int i = 0; i < 100000; i++)
        sp2.addNumber(rand() % 100000);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
}