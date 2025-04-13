#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(): 
    AForm("Shrubbery_form", "", 145, 137){
    throw ShrubberyCreationForm::EmptyTarget();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
    AForm("Shrubbery_form", target, 145, 137){
    if(this->getTarget() == "")
        throw ShrubberyCreationForm::EmptyTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::executeForm() const {
    std::ofstream file((getTarget() + "_shrubbery").c_str());
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file.close();
}

const char* ShrubberyCreationForm::EmptyTarget::what() const throw() {
    return "Missing target to shrubbery form!";
}