#include "../include/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("Default"),
    _grade(1){
    std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::string const   Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const{
    return _grade;
}

void    Bureaucrat::increaseGrade(){
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
    std::cout << "Increased grade of " << _name << " to " << _grade << std::endl;
}

void    Bureaucrat::decreaseGrade(){
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
    std::cout << "Decreased grade of " << _name << " to " << _grade << std::endl;
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat){
    output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return output;
}