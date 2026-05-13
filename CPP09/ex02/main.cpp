#include "include/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

class PmergeMe;

/// MAIN ///
int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		std::cerr << "Error: Invalid number of arguments";
		return -1;
	}

	PmergeMe pmergeMe;
	if (pmergeMe.insertNumbers(argc, argv) == false)
	{
		return -1;
	}
	
	// Check if we have some bad argument
	if (pmergeMe.checkDupAndNegative() == true){
		std::cerr << "Error: You can not have a duplicate number or a negative number in the input" << std::endl;
		return -1;
	}

	pmergeMe.printBefore(argc, argv);
	
	double vectorTime = pmergeMe.sortVector();
	double dequeTime = pmergeMe.sortDeque();

	pmergeMe.printAfter();
	pmergeMe.printTimeToSort(VECTOR, vectorTime, argc - 1);
	pmergeMe.printTimeToSort(DEQUE, dequeTime, argc - 1);

	return 0;
}