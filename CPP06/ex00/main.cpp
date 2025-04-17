#include "include/ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv){
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else{

        std::cout << "Invalid: ./cover <type>" << std::endl;
    }
    // TESTAR NA ESCOLA
    // float f = 12345678.12345678f;
    // double d = 12345678.12345678;
    // std::cout << d << " | " << f << std::endl;
}

//testes: "" | h | " " | ' ' | '' | 200 | 90 | -90 | 9 | -9 | -9a9 | 9a9 | - | '-' | "-" | 4,20 | -4,20 | 4,2a0 | -4,2a0 | 4, | -4, | 4.20f | -4.20f | 4.2a0 | -4.2a0 | -4.f | 4.f | 4.20fa | 4.20f9