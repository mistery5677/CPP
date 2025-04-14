#pragma once
#include <string>
#include "AForm.hpp"


class Intern {
    private:

    public:
        Intern();
        ~Intern();
        AForm *makeForm(std::string form, std::string target);
};