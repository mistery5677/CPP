#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

class ShrubberyCreationForm: public AForm {
    private:

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        void executeForm() const ;

        class EmptyTarget: public std::exception{
            public:
                const char* what() const throw();
        };
};