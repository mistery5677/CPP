#include "include/PmergeMe.hpp"
#include <iostream>

/// MAIN ///
int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		std::cerr << "Error: Invalid number of arguments";
		return -1;
	}

	PmergeMe pmergeMe;
	pmergeMe.insertNumbers(argc, argv);
	
	// Check if we have some bad argument
	if (pmergeMe.checkDupAndNegative() == true){
		std::cerr << "Error: You can have a duplicate number or a negative number in the input" << std::endl;
		exit(EXIT_FAILURE);
	}

	pmergeMe.printBefore(argc, argv);
	
	double vectorTime = pmergeMe.sortVector();
	double dequeTime = pmergeMe.sortDeque();

	return 0;
}

// Positive integer sequence as an argument