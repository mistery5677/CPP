#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

class RobotomyRequestForm: public AForm {
    private:

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        void executeForm() const ;

        class EmptyTarget: public std::exception{
            public:
                const char* what() const throw();
        };
};