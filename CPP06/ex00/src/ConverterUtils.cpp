#include <iostream>
#include <cstdlib>
#include <climits>

bool isChar(const std::string& literal){
    if (literal.size() == 1 && ((literal[0] >= 0 && literal[0] < '0') || literal[0] > '9'))
        return true;
    return false;
}

bool isInt(const std::string& literal){
    int i = 0;

    if (literal[i] == '-' || literal[i] == '+')
        i++;

    for (i = i; literal[i]; i++)
        if (literal[i] < '0' || literal[i] > '9')
            return false;
    return true;
}

bool isFloat(const std::string& literal){
    int i = 0;

    ///////////// CHECKS THE FIRST BITS ////////////
    
    if (literal[i] == '-' || literal[i] == '+')
        i++;

    for (i = i; literal[i]; i++)
        if (literal[i] < '0' || literal[i] > '9')
            break;
    
    //////////// SKIPS THE DOT ////////////

    if (literal[i] != '.')
        return false;
    i++;

    //////////// CHECKS THE SECOND BITS ///////////
    
    for (i = i; literal[i]; i++)
        if (literal[i] < '0' || literal[i] > '9')
            break ;
    
    if (literal[i] == 'f' && !literal[i + 1])
        return true;
    return false;
}

bool isDouble(const std::string& literal){
    int i = 0;

    ///////////// CHECKS THE FIRST BITS ////////////
    
    if (literal[i] == '-' || literal[i] == '+')
        i++;

    for (i = i; literal[i]; i++)
        if (literal[i] < '0' || literal[i] > '9')
            break;
    
    //////////// SKIPS THE DOT ////////////

    if (literal[i] != ',')
        return false;
    i++;

    //////////// CHECKS THE SECOND BITS ///////////
    
    for (i = i; literal[i]; i++)
        if (literal[i] < '0' || literal[i] > '9')
            return false;
    return true;
}

bool isSpecial(const std::string& literal){
    if (literal == "+inff" || literal == "-inff" || literal == "nanf"
        || literal == "+inf" || literal == "-inf" || literal == "nan")
            return true;
    return false;
}

void specialType(){
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "Int: " << "impossible" << std::endl;
    std::cout << "Float: " << "nanf" << std::endl;
    std::cout << "Double: " << "nan" << std::endl;
}

void charType(const std::string& literal){
    std::cout << "char: '" << literal << "'" << std::endl;
    std::cout << "Int: " << (int)literal[0] << std::endl;
    std::cout << "Float: " << (float)literal[0] << ".0f" << std::endl;
    std::cout << "Double: " << (double)literal[0] << ".0" << std::endl;
}

void intType(const std::string& literal){
    float   toFloat = std::atof(literal.c_str());
    int     toInt = std::atoi(literal.c_str());
    char    toChar = toInt;

    //////// PRINTS CHAR ////////
    if (toInt >= 32 && toInt <= 126)
        std::cout << "char: '" << toChar << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    char*    end;
    long    toLong = std::strtol(literal.c_str(), &end, 10); // base 10
    
    //////// PRINTS INT | FLOAT | DOUBLE ////////
    if (toLong > INT_MAX || toLong < INT_MIN){
        std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: Impossible" << std::endl;
        std::cout << "Double: Impossible" << std::endl;
    }
    else{
        std::cout << "Int: " << toInt << std::endl;
        std::cout << "Float: " << toFloat << "f" << std::endl;
        std::cout << "Double: " << toFloat << std::endl;
    }
}

int getType(const std::string& literal){
    if (isChar(literal))
        return 0;
    if (isInt(literal))
        return 1;
    if (isFloat(literal))
        return 2;
    if (isDouble(literal))
        return 3;
    if (isSpecial(literal))
        return 4; 
    return 10;
}
