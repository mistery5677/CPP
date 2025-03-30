#pragma once
#include <string>

class Brain{
    private:
    
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &src);
        virtual ~Brain();
        
        std::string *_ideas;
};