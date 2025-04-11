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
}