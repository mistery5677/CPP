#include "../include/AForm.hpp"
#include <iostream>

AForm::AForm(): _name("default"),
	_signed(false),
	_signGrade(50),
	_executeGrade(100){
}

AForm::AForm(std::string name, int const sign, int const execute): 
	_name(name),
	_signed(false),
	_signGrade(sign),
	_executeGrade(execute){
		if (sign < 1 || execute < 1)
			throw AForm::GradeTooHighException();
		else if (sign > 150 || execute > 150)
			throw AForm::GradeTooLowException();
}

AForm::~AForm(){
}

std::string const	AForm::getName() const{
	return _name;
}

bool	AForm::getSigned() const{
	return _signed;
}

int	AForm::getSignGrade() const{
	return _signGrade;
}

int	AForm::getExecuteGrade() const{
	return _executeGrade;
}

void	AForm::beSigned(Bureaucrat& bureaucrat){
	if (this->_signed == true)
		std::cout << "Form " << this->_name << " is already signed" << std::endl;
	else if (bureaucrat.getGrade() <= this->_signGrade){
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form is too low!";
}

std::ostream& operator<<(std::ostream& output, const AForm& aform){
	output << "The form " << aform.getName() << " is signed? " << aform.getSigned();
	output << "Form sign grade: " << aform.getSignGrade() << " Execute grade: " << aform.getExecuteGrade() << std::endl;
	return output;
}