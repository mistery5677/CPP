#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>


ShrubberyCreationForm::ShrubberyCreationForm(): 
    AForm("Shrubbery_form", "empty", 145, 137){
    throw ShrubberyCreationForm::EmptyTarget();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
    AForm("Shrubbery_form", target, 145, 137){
    if(this->getTarget() == "")
        throw ShrubberyCreationForm::EmptyTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor){
    (void) executor;
    std::cout << "Executei a funcao execute" << std::endl;
}

const char* ShrubberyCreationForm::EmptyTarget::what() const throw() {
    return "Missing target to shrubbery form!";
}