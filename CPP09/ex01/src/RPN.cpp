#include "../include/RPN.hpp"

Calculator::Calculator(){
}

Calculator::Calculator(char **argv){
    this->calculate(argv);
}

Calculator::Calculator(const Calculator& cpy){
    this->_memory = cpy._memory;
}

Calculator& Calculator::operator=(const Calculator& cpy){
    if (this != &cpy) {
        _memory = cpy._memory;
    }
    return *this;
}

void Calculator::calculate(char **argv){
    for (int i = 0; argv[i]; i++){
        if (isOperand)
        _memory.push(std::atoi(argv[i]))
    }
}

bool isOperand(char c){
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool isOperator(char c){
    if (c == '+' && c == '-'
        && c == '/' && c == '*')
        return true;
    return false;
}

bool checkStr(char *str){
    for (int x = 0; str[x]; x++){
        if ((str[x] != '/' && str[x] != '*'
            && str[x] != '+' && str[x] != '-')
            && !(str[x] >= '0' && str[x] <= '9')){
                return false;
            }
    }
    return true;
}

bool checkInput(int argc, char **argv){
    if (argc == 1){
        std::cerr << "Error: Invalid argument number" << std::endl;
        return false;
    }
    for (int i = 1; argv[i]; i++){
        for (int x = 0; argv[i][x]; x++){
            if (!checkStr(argv[i])){
                std::cerr << "Error: Bad argument: " << argv[i] << std::endl;
                return false;
            }
        }
    }
    return true;
}