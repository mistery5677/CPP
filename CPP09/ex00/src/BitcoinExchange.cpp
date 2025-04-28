#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <cmath>

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

bool checkTitles(const std::string line){
    // Checks if the line is not empty
    if (!line.c_str())
        throw std::invalid_argument("ERROR: Nothing inside in data base\n");

    size_t divider = line.find(",");
    // Checks if have any divider
    if (divider == std::string::npos)
        throw std::invalid_argument("ERROR: No division detected in input file -> date | exchange_rate\n");

    // Get the informatioon in the left and right side
    std::string date = line.substr(0, divider);
    std::string value = line.substr(divider + 1);

    // Removes all the possible spaces before and after the word
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    date.erase(0, date.find_first_not_of(" \n\r\t"));
    value.erase(value.find_last_not_of(" \n\r\t") + 1);
    value.erase(0, value.find_first_not_of(" \n\r\t"));

    // Compares if matches the names
    if (date != "date" || value != "exchange_rate")
        throw std::invalid_argument("ERROR: The titles are wrong -> date | exchange_rate\n");
    return true;
}

// void checkInformation(std::string& date, std::string& value){
//     date.erase(date.find_last_not_of(" \n\r\t") + 1);
//     date.erase(0, date.find_first_not_of(" \n\r\t"));
//     value.erase(value.find_last_not_of(" \n\r\t") + 1);
//     value.erase(0, value.find_first_not_of(" \n\r\t"));

//     std::istringstream dateCopy;
//     std::getline(dateCopy, date, '-');
//     if (std::atoi(dateCopy.c_str()))

// }

void BitcoinExchange::loadDataBase(){
    // Opens the file
    std::ifstream file("data.csv");
    if(!file.is_open()){
        throw std::invalid_argument("Error: Couldn't open the file\n");
        return ;
    }

    // Checks the first line
    std::string line;
    std::getline(file, line);
    if (!checkTitles(line))
        throw std::invalid_argument("Error: Empty file\n");
    
    int divider = line.find(",");
    std::string date = line.substr(0, divider);
    std::string value = line.substr(divider + 1);

    while (std::getline(file, line)){
        divider = line.find(",");
        date = line.substr(0, divider);
        value = line.substr(divider + 1);
        this->_dataBase[date] = atoi(value.c_str());
    }

    for (std::map<std::string, float>::const_iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); ++it) {
        std::cout << "Data: " << it->first << " | Preço: " << it->second << std::endl;
    }
    

    file.close();
}