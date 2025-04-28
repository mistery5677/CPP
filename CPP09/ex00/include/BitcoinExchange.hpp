#pragma once
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> _dataBase; // Container
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange &operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();

        //UTILS
        void    loadDataBase();
};