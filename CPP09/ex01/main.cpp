#include "include/RPN.hpp"

int main(int argc, char **argv){
    // Checks the input
    if (argc != 2){
        std::cerr << "Error: Invalid argument number" << std::endl;
        return false;
    }
    Calculator calculator;

    calculator.calculate(argv[1]);
}