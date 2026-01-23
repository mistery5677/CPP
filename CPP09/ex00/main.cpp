#include "include/BitcoinExchange.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv){
    (void)argv;
    if (argc != 2){
        std::cerr << "Syntaxe Error: ./btc <input_file>" << std::endl;
        return -1;
    }

    try {
        BitcoinExchange test;
        test.readInputFile(argv[1]);
    } catch (const std::exception& msg){
        std::cout << msg.what() << std::endl;
    }
}