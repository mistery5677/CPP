#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"
#include <iostream>

int main(){
    
    std::cout << "\n*********TESTING CONSTRUCTOR**********\n" << std::endl;
	try {
		Form test("test", 10, 190);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	try {
		Form test1("test1", 10, 0);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	try {
		Form test2("test2", 190, 10);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	try {
		Form test3("test3", 0, 100);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\n*********TESTING GRADE 10 FORM 100**********\n" << std::endl;
	try {
		Bureaucrat miguel("Miguel", 10);
		Form form("test", 100, 120);
		miguel.signForm(form);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\n*********TESTING GRADE 10 FORM 1**********\n" << std::endl;
	try {
		Bureaucrat miguel("Miguel", 10);
		Form form("test", 1, 120);
		miguel.signForm(form);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}

	std::cout << "\n*********TESTING GRADE 10 FORM 10**********\n" << std::endl;
	try {
		Bureaucrat miguel("Miguel", 10);
		Form form("test", 10, 120);
		miguel.signForm(form);
		miguel.signForm(form);
	} catch (std::exception &msg) {
		std::cout << "Error: " << msg.what() << std::endl;
	}
}