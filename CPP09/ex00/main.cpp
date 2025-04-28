#include "include/BitcoinExchange.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv){
    (void)argv;
    if (argc != 2){
        std::cerr << "Syntaxe Error: ./btc <input_file>" << std::endl;
        return -1;
    }
    
    std::cout << "\033[1;31m";
    std::cout << "*******TESTING DEFAULT CONSTRUCTOR*******\n" << std::endl;
    std::cout << "\033[1;0m";

    try {
        BitcoinExchange test;
        (void)test;

    } catch (const std::exception& msg){
        std::cout << msg.what() << std::endl;
    }
}