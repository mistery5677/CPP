#pragma once
#include <deque>
#include <vector>
#include <string>

class PmergeMe{
    private:
        std::deque<int>     _pend;
        std::vector<int>    _main;
    public:
        PmergeMe();									// Default constructor
		PmergeMe(char** argv);						// Parameterized Constructor
        PmergeMe(const PmergeMe& cpy);				// Copy constructor
        PmergeMe& operator=(const PmergeMe& cpy);	// Overloading operator
        ~PmergeMe();								// Default desconstructor

		void 				BuildContainers(char** numbers);

		// Getters
		std::vector<int> 	GetVector();
		std::deque<int>		GetDeque();
};
