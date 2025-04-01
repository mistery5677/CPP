#pragma once
#include <string>

class Cure {
    private:
        std::string _type;
    public:
        Cure();
        Cure(std::string type);
        Cure(const Cure &copy);
        Cure &operator=(const Cure &src);
        virtual ~Cure();
};
