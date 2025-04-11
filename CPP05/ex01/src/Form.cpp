#include "../include/Form.hpp"
#include <iostream>

Form::Form(): _name("default"),
	_signed(false),
	_signGrade(50),
	_executeGrade(100){
}

Form::Form(std::string name, int const sign, int const execute): 
	_name(name),
	_signed(false),
	_signGrade(sign),
	_executeGrade(execute){
		if (sign < 1 || execute < 1)
			throw Form::GradeTooHighException();
		else if (sign > 150 || execute > 150)
			throw Form::GradeTooLowException();
}

Form::~Form(){
}

std::string const	Form::getName() const{
	return _name;
}

bool	Form::getSigned() const{
	return _signed;
}

int	Form::getSignGrade() const{
	return _signGrade;
}

int	Form::getExecuteGrade() const{
	return _executeGrade;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form is too low!";
}

std::ostream& operator<<(std::ostream& output, const Form& form){
	output << "The form " << form.getName() << " is signed? " << form.getSigned();
	output << "Form sign grade: " << form.getSignGrade() << "   Execute grade: " << form.getExecuteGrade() << std::endl;
	return output;
}