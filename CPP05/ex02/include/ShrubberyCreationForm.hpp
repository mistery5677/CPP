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
        void execute(Bureaucrat const & executor);

        class EmptyTarget: public std::exception{
            public:
                const char* what() const throw();
        };
};