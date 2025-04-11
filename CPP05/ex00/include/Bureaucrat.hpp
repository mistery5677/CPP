#pragma once
#include <string>
#include <exception>

class Bureaucrat {
    private:
        std::string const   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        std::string const   getName() const;
        int                 getGrade() const;
        void                increaseGrade();
        void                decreaseGrade();

        class GradeTooHighException: public std::exception{
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};