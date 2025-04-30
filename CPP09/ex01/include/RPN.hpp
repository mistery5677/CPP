#pragma once
#include <stack>
#include <iostream>

class Calculator{
    private:
        std::stack<int> _memory;
    public:
        Calculator(); // Constructor default
        Calculator(char **argv); // Construct with input 
        Calculator(const Calculator& copy); // Copy constructor
        Calculator& operator=(const Calculator& copy); // Operator overloading
        ~Calculator(); // Desconstructor
    
        void calculate(char **argv);
};

bool isOperand(char c);
bool isOperator(char c);
bool checkStr(char *str);
bool checkInput(int argc, char **argv);