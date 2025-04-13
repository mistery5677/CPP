#pragma once
#include "../include/Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        std::string const   _name;
		std::string const	_target;
        bool                _signed;
    	int const           _signGrade;
        int const           _executeGrade;
	public:
		AForm();
		AForm(std::string name, std::string target, int const sign, int const execute);
		virtual ~AForm();

		//Getters
		std::string const	getName() const;
		std::string const	getTarget() const;
		bool				getSigned() const;
		int 				getSignGrade() const;
		int 				getExecuteGrade() const;
		void				beSigned(Bureaucrat& bureaucrat);
		
		////////// PART 3 /////////
		virtual void	executeForm() const = 0;
		void			execute(Bureaucrat const & executor);

		//Throw execptions
		class GradeTooHighException: public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class UnsignedForm: public std::exception {
            public:
                const char* what() const throw();
        };

};
//Overload insertion
std::ostream& operator<<(std::ostream& output, const AForm& form);