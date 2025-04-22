#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"

int main() {

    std::cout << "\033[31m";
    std::cout << "\n******************************************";
    std::cout << "\n*********TESTING FORM CRATION*************";
    std::cout << "\n******************************************\n" << std::endl;
    std::cout << "\033[0m";

    Intern someRandomIntern;
    AForm* rrf;
    AForm* pp;
    AForm* shrubbery;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    pp = someRandomIntern.makeForm("presidential pardon", "Prison");
    shrubbery = someRandomIntern.makeForm("shrubbery creation", "Garden");
    
    std::cout << "\033[31m";
    std::cout << "\n******************************************";
    std::cout << "\n*********TESTING WRONG FORMS**************";
    std::cout << "\n******************************************\n" << std::endl;
    std::cout << "\033[0m";

    AForm* error;
    AForm* error2;

    error = someRandomIntern.makeForm("", "Bender");
    error2 = someRandomIntern.makeForm("presidential pardonn", "Bender");

    std::cout << "\033[31m";
    std::cout << "\n******************************************";
    std::cout << "\n*********TESTING SIGNING FORMS************";
    std::cout << "\n******************************************\n" << std::endl;
    std::cout << "\033[0m";

    Bureaucrat* miguel = new Bureaucrat("miguel", 100);

    try {
        miguel->signForm(*rrf);
        miguel->signForm(*pp);
        miguel->signForm(*shrubbery);
        miguel->signForm(*error);
        miguel->signForm(*error);
        shrubbery->execute(*miguel);
    } catch(std::exception &msg){
        std::cout << "ERROR:" << msg.what() << std::endl;
    }

    delete rrf;
    delete pp;
    delete shrubbery;
    delete error;
    delete error2;
	delete miguel;
}
