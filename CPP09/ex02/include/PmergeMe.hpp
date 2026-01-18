#pragma once
#include <deque>
#include <vector>
#include <string>

#define VECTOR 1
#define DEQUE 2

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
		double sortVector();						// Sort the vector container and return the time wasted;
		double sortDeque();							// Sort the deque container and return the time wasted;
        
        void printBefore(int argc, char **argv);
        void printAfter();
        void printTimeToSort(int type, double time, size_t ctrSize);
        void PrintContainers();
};

class Pair{
    public:
        //Orthodox way
        Pair();								// Default constructor
        Pair(const Pair& cpy);				// Copy constructor
        Pair& operator=(const Pair& cpy);	// Overloading operator
        ~Pair();							// Default desconstructor

        // Values
        int small;
        int big;
};