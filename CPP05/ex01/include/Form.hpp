#pragma once
#include "../include/Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        std::string const   _name;
        bool                _signed;
        int const           _signGrade;
        int const           _executeGrade;
    
	public:
		Form();
		Form(std::string name, int const sign, int const execute);
		~Form();

		//Getters
		std::string const	getName() const;
		bool				getSigned() const;
		int 				getSignGrade() const;
		int 				getExecuteGrade() const;
		void				beSigned(Bureaucrat& bureaucrat);
		
		//Throw execptions
		class GradeTooHighException: public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

};
//Overload insertion
std::ostream& operator<<(std::ostream& output, const Form& form);