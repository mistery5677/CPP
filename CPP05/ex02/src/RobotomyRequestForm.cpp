#include "../include/RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(): 
    AForm("RobotRequest_form", "", 72, 45){
    throw RobotomyRequestForm::EmptyTarget();
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
    AForm("RobotRequest_form", target, 72, 45){
    if(this->getTarget() == "")
        throw RobotomyRequestForm::EmptyTarget();
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::executeForm() const {
    srand(time(0));
    int randomNum = rand() % 100;
    
    std::cout << "DRRRR DRRRR DRRRRR ... ";
    if (randomNum % 2 == 0)
        std::cout << getTarget() << " has been robotomized 🤖🤖" << std::endl;
    else
        std::cout << getTarget() << " failed to robotomy :(" << std::endl;
}

const char* RobotomyRequestForm::EmptyTarget::what() const throw() {
    return "Missing target to shrubbery form!";
}