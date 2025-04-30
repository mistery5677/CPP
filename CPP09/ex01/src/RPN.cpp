#include "../include/RPN.hpp"
#include <stdlib.h> // atoi
#include <sstream>
#include <string>

Calculator::Calculator(){
}

Calculator::Calculator(char *argv){
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

Calculator::~Calculator(){
}

bool isOperand(std::string& str){
    if (str[0] < '0' || str[0] > '9')
        return false;

    if (str[1]) // Checks if the str is finished
        return false;
    return true;
}

bool isOperator(std::string& str){
    if (str[0] != '+' && str[0] != '-'
        && str[0] != '/' && str[0] != '*') // Check the operator
        return false;

    if (str[1]) // Checks if the str is finished
        return false;
    return true;
}

bool checkInput(char *argv){
    std::stringstream   ss(argv);
    std::string         value;
    while (std::getline(ss, value, ' ')){ // Checks the entire arguments
        if (value.empty()) // If we have more than one space together
            continue ;
        if (!isOperator(value) && !isOperand(value)){ // If we don't have an operator or an operand
            std::cerr << "Error: Bad argument: " << value << std::endl;
            return false;
        }
    }
    return true;
}

// Will do the maths
bool Calculator::doOperation(char oprt){
    //Get the values;
    int top1 = this->_memory.top();
    this->_memory.pop();

    int top2 = this->_memory.top();
    this->_memory.pop();

    if (oprt == '+')
    this->_memory.push(top2 + top1);
    else if (oprt == '-')
    this->_memory.push(top2 - top1);
    else if (oprt == '*')
    this->_memory.push(top2 * top1);
    else if (oprt == '/'){
        if (top1 == 0){
            std::cerr << "Error: Divided by 0" << std::endl;
            return false;
        }
        else
            this->_memory.push(top2 / top1);
    }
    return true;
}

void Calculator::calculate(char *argv){
    // Checks the input if it is valid
    if (!checkInput(argv))
        return ;

    std::stringstream   ss(argv);
    std::string         value;
    while (std::getline(ss, value, ' ')){ // This will split the line
        if (value.empty())
            continue ;

        if (isOperand(value))
            this->_memory.push(std::atoi(value.c_str()));
        else if (this->_memory.size() >= 2){ // If it is not an operand, i have to check if i have enough operands to make the operation
            if (!this->doOperation(value[0]))
                return ;
        }
        else {
            std::cerr << "Error: Trying to do a operation without any operand in stack" << std::endl;
            return ;
        }
    }
    if (this->_memory.size() > 1)
        std::cerr << "Error: Missing some operands to finish" << std::endl;
    else
        std::cout << "Result: " << this->_memory.top() << std::endl;
}
