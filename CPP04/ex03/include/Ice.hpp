#pragma once
#include <string>

class Ice {
    private:
        std::string _type;
    public:
        Ice();
        Ice(std::string type);
        Ice(const Ice &copy);
        Ice &operator=(const Ice &src);
        virtual ~Ice();
};