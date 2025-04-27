#pragma once
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> _data; // Container
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string fileName);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange &operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();

        //UTILS
        void    loadData(const std::string fileName);
};