#pragma once
#include <deque>
#include <vector>
#include <string>

class PmergeMe{
    private:
        std::deque<int>     _deque;
        std::vector<int>    _vector;
    public:
        PmergeMe();									// Default constructor
        PmergeMe(const PmergeMe& cpy);				// Copy constructor
        PmergeMe& operator=(const PmergeMe& cpy);	// Overloading operator
        ~PmergeMe();								// Default desconstructor

		void insertNumbers(int argc, char **argv); 	// Insert the numbers in each container
		bool checkDupAndNegative();					// Check if we found a negative or a duplicated number
		void printBefore(int argc, char **argv);
		double sortVector();						// Sort the vector container and return the time wasted;
		double sortDeque();							// Sort the deque container and return the time wasted;

		void PrintContainers();
};
