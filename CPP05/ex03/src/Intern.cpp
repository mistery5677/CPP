#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"

Intern::Intern(){
    std::cout << "\033[32m";
    std::cout << "Intern can make this forms: 'presidential pardon' | 'robotomy request' | 'shrubbery creation'" << std::endl;
    std::cout << "\033[0m";
}

Intern::~Intern(){
}

AForm   *Intern::makeForm(std::string form, std::string target){
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i;

    for (i = 0; i < 3 && forms[i] != form; i++)
        continue;

    switch (i) {
        case 0:
            std::cout << "Intern creates " << form << std::endl;
            return new PresidentialPardonForm(target);
        case 1:
            std::cout << "Intern creates " << form << std::endl;
            return new RobotomyRequestForm(target);
        case 2  :
            std::cout << "Intern creates " << form << std::endl;
            return new ShrubberyCreationForm(target);
        default:
            std::cout << "Invalid form: " << form << std::endl;
            return NULL;
    }
}