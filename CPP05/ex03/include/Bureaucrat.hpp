#pragma once
#include "AForm.hpp"
#include <string>
#include <exception>
#include <iostream>

class AForm;

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
        void    signForm(AForm& form);
};
std::ostream&    operator<<(std::ostream& output, const Bureaucrat& bureaucrat);