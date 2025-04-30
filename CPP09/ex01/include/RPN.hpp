#pragma once
#include <stack>
#include <iostream>

class Calculator{
    private:
        std::stack<int> _memory;
    public:
        Calculator(); // Constructor default
        Calculator(char *argv); // Construct with input 
        Calculator(const Calculator& copy); // Copy constructor
        Calculator& operator=(const Calculator& copy); // Operator overloading
        ~Calculator(); // Desconstructor
    
        void calculate(char *argv);
        bool doOperation(char oprt);
};

bool isOperand(std::string& str);
bool isOperator(std::string& str);
// bool checkStr(char *str);
bool checkInput(char *argv);