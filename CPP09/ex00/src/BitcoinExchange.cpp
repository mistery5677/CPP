#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const std::string fileName){
    loadData(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){
    this->_data = copy._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
    if(this != &copy)
        this->_data = copy._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){
}

bool checkTitles(const std::string line){
    // Checks if the line is not empty
    if (!line.c_str()){
        std::cerr << "ERROR: Nothing inside the input file" << std::endl;
        return false;
    }

    size_t divider = line.find("|");
    // Checks if have any divider
    if (divider == std::string::npos){
        std::cerr << "ERROR: No division detected in input file -> date | value" << std::endl;
        return false;
    }

    // Get the informatioon in the left and right side
    std::string date = line.substr(0, divider);
    std::string value = line.substr(divider + 1);

    // Removes all the possible spaces before and after the word
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    date.erase(0, date.find_first_not_of(" \n\r\t"));
    value.erase(value.find_last_not_of(" \n\r\t") + 1);
    value.erase(0, value.find_first_not_of(" \n\r\t"));

    // Compares if matches the names
    if (date != "date" || value != "value"){
        std::cerr << "ERROR: The titles are wrong -> date | value" << std::endl;
        return false;
    }
    return true;
}

void checkInformation(const std::string line){

}

void BitcoinExchange::loadData(const std::string fileName){
    // Opens the file
    std::ifstream file(fileName.c_str());
    if(!file.is_open()){
        std::cerr << "Error: Couldn't open the file" << std::endl;
        return ;
    }

    // Checks the title
    std::string line;
    std::getline(file, line);
    if (!checkTitles(line))
        return ;
    
    int divider = line.find("|");
    std::string date = line.substr(0, divider);
    std::string value = atof(line.substr(divider + 1));
    while (std::getline(file, line)){
        divider = line.find("|");
        date = line.substr(0, divider);
        value = line.substr(divider + 1);
        this->_data.insert({date, value})
    }

    file.close();
}