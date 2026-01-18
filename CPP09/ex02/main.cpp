#include "include/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

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
		std::cerr << "Error: You can not have a duplicate number or a negative number in the input" << std::endl;
		exit(EXIT_FAILURE);
	}

	pmergeMe.printBefore(argc, argv);
	
	double vectorTime = pmergeMe.sortVector();
	double dequeTime = pmergeMe.sortDeque();

	pmergeMe.printAfter();
	pmergeMe.printTimeToSort(VECTOR, vectorTime, argc - 1);
	pmergeMe.printTimeToSort(DEQUE, dequeTime, argc - 1);

	// std::cout << "Estamos a imprimir os Containers depois de dar sort" << std::endl;
	// pmergeMe.PrintContainers();
	return 0;
}

// Positive integer sequence as an argument