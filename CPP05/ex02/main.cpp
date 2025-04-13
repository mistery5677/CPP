#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"

int main(){

    std::cout << "\n*********TESTING FORMSCONSTRUCTOR**********\n" << std::endl;
    try {
        AForm shrubbery = ShrubberyCreationForm("house");
        Bureaucrat miguel("Miguel", 10);
        std::cout << "Form name " << shrubbery.getName() << " | Target: " << shrubbery.getTarget() << " | Sign grade: " << shrubbery.getSignGrade() << " |Execute grade: " << shrubbery.getExecuteGrade() << std::endl;
        shrubbery.execute(miguel);
        
        AForm error = ShrubberyCreationForm("");
    } catch (std::exception &msg){
        std::cout << "Error: " << msg.what() << std::endl;
    }
    
}