#include "../include/PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(): 
    AForm("PresidentialPardon_form", "", 25, 5){
    throw PresidentialPardonForm::EmptyTarget();
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
    AForm("PresidentialPardon_form", target, 25, 5){
    if(this->getTarget() == "")
        throw PresidentialPardonForm::EmptyTarget();
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::executeForm() const {
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char* PresidentialPardonForm::EmptyTarget::what() const throw() {
    return "Missing target to shrubbery form!";
}