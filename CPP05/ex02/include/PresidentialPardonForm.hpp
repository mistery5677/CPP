#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

class PresidentialPardonForm: public AForm {
    private:

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        void executeForm() const ;

        class EmptyTarget: public std::exception{
            public:
                const char* what() const throw();
        };
};