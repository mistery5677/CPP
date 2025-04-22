#pragma once
#include <string>
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define SPECIAL 4

class ScalarConverter{
    private:

    public:
		ScalarConverter();
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter &src);
        ~ScalarConverter();
        
        static void convert(const std::string& literal); // As a static method, you don't need to create an object to use
};