#pragma once
#include "Form.hpp"
#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat {
    private:
        std::string const   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        std::string const       getName() const;
        int                     getGrade() const;
        void                    increaseGrade();
        void                    decreaseGrade();
        
        class GradeTooHighException: public std::exception{
            public:
            const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
            const char* what() const throw();
        };
        
        /////////// PART 2 //////////
        void    signForm(Form& form);
};
std::ostream&    operator<<(std::ostream& output, const Bureaucrat& bureaucrat);