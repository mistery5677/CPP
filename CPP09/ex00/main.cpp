#include "include/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv){
    (void)argv;
    if (argc != 2){
        std::cerr << "Syntaxe Error: ./btc <input_file>" << std::endl;
        return -1;
    }
    
    std::cout << "\033[1;31m";
    std::cout << "*******TESTING DEFAULT CONSTRUCTOR*******\n" << std::endl;
    std::cout << "\033[1;0m";

    BitcoinExchange test_default;
    (void)test_default;

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING CONSTRUCTOR*******\n" << std::endl;
    std::cout << "\033[1;0m";

    BitcoinExchange test(argv[1]);
    (void)test;
}