#include "include/Bureaucrat.hpp"
#include <iostream>

int main(){
    
    std::cout << "\n*********TESTING CONSTRUCTOR**********\n" << std::endl;
    Bureaucrat miguel("Miguel", 2);

    std::cout << "\n*********TESTING CONSTRUCTOR WITH HIGHER AND LOWER GRADES**********\n" << std::endl;

    try {
        Bureaucrat miguel = Bureaucrat("Joao", 0);
    } catch (std::exception &msg) {
        std::cout << "Error: " << msg.what() << std::endl;
    }
    try {
        Bureaucrat miguel = Bureaucrat("Lucas", 151);
    } catch (std::exception &msg) {
        std::cout << "Error: " << msg.what() << std::endl;
    }

    std::cout << "\n*********TESTING INCREASEGRADE**********\n" << std::endl;
    try {
        Bureaucrat miguel = Bureaucrat("Lucas", 3);
        miguel.increaseGrade();
        miguel.increaseGrade();
        miguel.increaseGrade();
        miguel.increaseGrade();
    } catch (std::exception &msg) {
        std::cout << "Error: " << msg.what() << std::endl;
    }

    std::cout << "\n*********TESTING INCREASEGRADE**********\n" << std::endl;
    try {
        Bureaucrat miguel = Bureaucrat("Lucas", 148);
        miguel.decreaseGrade();
        miguel.decreaseGrade();
        miguel.decreaseGrade();
        miguel.decreaseGrade();
    } catch (std::exception &msg) {
        std::cout << "Error: " << msg.what() << std::endl;
    }

}