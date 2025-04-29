#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <stdlib.h>

BitcoinExchange::BitcoinExchange(){
    loadDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){
    this->_dataBase = copy._dataBase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
    if(this != &copy)
        this->_dataBase = copy._dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){
}

// Removes the spaces before and after the string
void    removeSpace(std::string& str){
    // Removes all the possible spaces before and after the word
    size_t end = str.find_last_not_of(" \n\r\t");
    size_t start = str.find_first_not_of(" \n\r\t");
    if (start == std::string::npos || end == std::string::npos) {
        str = "";
        return;
    }
    str = str.substr(start, end - start + 1);
}

void BitcoinExchange::loadDataBase(){
    // Opens the file
    std::ifstream file("data.csv");
    if(!file.is_open())
        throw std::invalid_argument("Error: Couldn't open the file\n");

    // Skips the first line
    std::string line;
    std::getline(file, line);

    
    // Checks line by line
    while (std::getline(file, line)){
        size_t divider = line.find(",");
        if (divider == std::string::npos)
            continue;
        std::string date = line.substr(0, divider);
        std::string value = line.substr(divider + 1);
        removeSpace(date);
        removeSpace(value);
        this->_dataBase[date] = std::atof(value.c_str());
    }
    file.close();
}

// Counts how many times apear 'ch' in 'str'
int countChar(const std::string& str, char ch) {
    int count = 0;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (*it == ch) {
            ++count;
        }
    }
    return count;
}

bool    checkTitles(const std::string line){
    // Checks if the line is not empty
    if (!line.c_str())
        throw std::invalid_argument("ERROR: Nothing inside in data base\n");

    size_t divider = line.find("|");
    // Checks if have any divider
    if (divider == std::string::npos)
        throw std::invalid_argument("ERROR: No division detected in input file -> date | value\n");

    // Get the informatioon in the left and right side
    std::string date = line.substr(0, divider);
    std::string value = line.substr(divider + 1);

    removeSpace(date);
    removeSpace(value);

    // Compares if matches the names
    if (date != "date" || value != "value")
        throw std::invalid_argument("ERROR: The titles are wrong -> date | value\n");
    return true;
}

// Checks if the string is only digits
bool isOnlyDigits(const std::string& str) {
    if (str.empty()) 
        return false;

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}

// Validates the days numbers
bool    checkDateInfo(int year, int month, int day){
    // Checks year
    if (year == 0){
        std::cout << "Error: Invalid year: " << year << std::endl;
        return false;
    }

    // Checks month
    if (month > 12 || month == 0){
        std::cout << "Error: Invalid month: " << month << std::endl;
        return false;
    }
    
    // Check day
    if (day > 31 || day == 0){
        std::cout << "Error: Invalid day: " << day << std::endl;
        return false;
    }
    
    // Checks year
    if (year < 2009 || (year == 2009 && month == 1 && day == 1)){
        std::cout << "Error: Bitcoin doesn't exist in " << year << "-" << month << "-" << day << std::endl;
        return false;
    }
    
    // Checks the day and the month
    if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)){
        std::cout << "Error: Day doesn't exist on that month." << std::endl;
        return false;
    }

    // Checks the day in february
    if (day > 28 && month == 2 && year % 4 != 0){
        std::cout << "Error: Day doesn't exist on that month." << std::endl;
        return false;
    }

    // Checks the day in february with 29 days
    if (day > 29 && month == 2 && year % 4 ==0){
        std::cout << "Error: Day doesn't exist on that month." << std::endl;
        return false;
    }
    return true;
}

bool    checkDate(std::string& date){
    removeSpace(date);

    std::stringstream ss(date);

    // Separates year | Month | day
    std::string year;
    std::string month;
    std::string day;

    // Delimits the information
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, '-');

    if (!isOnlyDigits(year) ||
        !isOnlyDigits(month) ||
        !isOnlyDigits(day)){
            std::cout << "Error: Alphabet dates" << std::endl;
            return false; 
        }
    
    // Checks date format
    if (countChar(date, '-') != 2 || year.size() != 4 || month.size() != 2 || day.size() != 2){
        std::cout << "Error: Incorrect date format YYYY-MM-DD" << std::endl;
        return false;
    }

    // Get the values into int
    int yearI = atoi(year.c_str());
    int monthI = atoi(month.c_str());
    int dayI = atoi(day.c_str());

    if (!checkDateInfo(yearI, monthI, dayI))
        return false;
    
    return true;
}

bool    checkValue(std::string& value){
    removeSpace(value);

    float valueF = std::atof(value.c_str());
    if (valueF > 1000){
        std::cout << "Error: Too large number" << std::endl;
        return false;
    }
    else if (valueF < 0){
        std::cout << "Error: Not a positive number" << std::endl;
        return false;
    }

    size_t delimiter = value.find('.');
    std::string exponent;
    if (delimiter == std::string::npos)
        exponent = value;
    else{
        exponent = value.substr(0, delimiter);
        std::string significant = value.substr(delimiter + 1);
        if (!significant.c_str() || !isOnlyDigits(significant)){

            std::cout << "Error: Bad value => " << value << std::endl;
            return false;
        }
    }
    if (!exponent.c_str() || !isOnlyDigits(exponent)){
        std::cout << "Error: Bad value => " << value << std::endl;
        return false;
    }
    return true;
}

std::map<std::string, float>::const_iterator targetDate(std::map<std::string, float> db, const std::string& date){
    std::map<std::string, float>::const_iterator it = db.upper_bound(date);
    if (it == db.begin()){
        it = db.end();
        return it;
    }
    --it;
    return it;
}

void    printWallet(std::map<std::string, float> db, const std::string& date, const std::string& value){
    std::map<std::string, float>::const_iterator  dataDB = targetDate(db, date);

    float valueF = std::atof(value.c_str());
    std::cout << dataDB->first << " => " << valueF << " = " << valueF * dataDB->second << std::endl;
}

void BitcoinExchange::readInputFile(const std::string fileName){
    // Open the fileName
    std::ifstream file(fileName.c_str());
    if(!file.is_open()){
        throw std::invalid_argument("Error: Couldn't open the input file\n");
        return ;
    }

    // Checks the first line
    std::string line;
    std::getline(file, line);
    checkTitles(line);

    // Set the values to the date and value
    int divider = line.find("|");
    std::string date = line.substr(0, divider);
    std::string value = line.substr(divider + 1);

    // Checks line by line
    while (std::getline(file, line)){
        // Checks if have the right number of '|'
        if (countChar(line, '|') != 1){
            std::cout << "Error: Bad input => " << line << std::endl;
            continue;
        }

        divider = line.find("|");
        date = line.substr(0, divider);
        value = line.substr(divider + 1);
        if (!checkDate(date) || !checkValue(value))
            continue;
        else
            printWallet(this->_dataBase, date, value);
    }

    file.close();
}