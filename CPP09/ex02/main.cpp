#include "include/PmergeMe.hpp"
#include <iostream>

void DB_PrintVector(std::vector<int> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}


void DB_PrintDeque(std::deque<int> deque)
{
	for (size_t i = 0; i < deque.size(); i++)
	{
		std::cout << deque[i] << " ";
	}
	std::cout << std::endl;
}

/// MAIN ///
int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		std::cerr << "Error: Invalid number of arguments";
		return -1;
	}

	PmergeMe pmergeMe(argv);
	DB_PrintVector(pmergeMe.GetVector());
	DB_PrintDeque(pmergeMe.GetDeque());

	

	return 0;
}

// Positive integer sequence as an argument