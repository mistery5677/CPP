#include "../include/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

/// @brief Default methods for class ///

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe& cpy){
    this->_deque = cpy._deque;
    this->_vector = cpy._vector;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy){
    if (this != &cpy){
        this->_deque = cpy._deque;
        this->_vector = cpy._vector;
    }

	return *this;
}

/// Default methods for class ///

/// @brief This method will verify and insert all numbers in each container
/// @param argc Number of arguments
/// @param argv The value of each argument
void PmergeMe::insertNumbers(int argc, char **argv){

	// Validate all the numbers in the arguments
	for (int x = 1; argv[x]; x++){
		for (int y = 0; argv[x][y]; y++){
			if (argv[x][y] < '0' || argv[x][y] >'9'){
				std::cerr << "Error: FOUND AN INVALID NUMBER" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}

	// Pass all the numbers to each container
	for (int x = 1; x < argc; x++){
		_vector.push_back(atoi(argv[x]));
		_deque.push_back(atoi(argv[x]));
	}
}

/// @brief Check if we have any negative or dup number
/// @return True if we find any of this conditions, otherwise is false
bool PmergeMe::checkDupAndNegative(){
	int vectorSize = _vector.size();

	for (int x = 0; x < vectorSize - 1; x++){
		if (_vector[x] < 0)
			return true;
		for (int y = x + 1; y < vectorSize; y++){
			if (_vector[x] == _vector[y])
				return true;
		}
	}

	return false;
}

void PmergeMe::printBefore(int argc, char **argv){
	std::cout << "Before: ";
	for (int x = 1; x < argc; x++){
		std::cout << argv[x] << " " << std::endl;
	}
}

double PmergeMe::sortVector(){
	clock_t start = clock();
	orderVector(0, _vector.size() - 1);
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
}

void orderVector(int start, int end){
	if (start < end){
		if (end - start <= 10)
			insertVector(start, end);
		else{
			int mid = start + (end - start) / 2;
			orderVector(start, mid);
			orderVector(mid + 1, end)
		}
	}
}

/// @brief Debug to print the containers
void PmergeMe::PrintContainers(){
	std::cout << "Printing Vector: ";
	for (std::vector<int>::iterator i = _vector.begin(); i != _vector.end(); i++){
		std::cout << *i << " ";
	}

	std::cout << "\nPrinting Deque: ";

	for (std::deque<int>::iterator i = _deque.begin(); i != _deque.end(); i++){
		std::cout << *i << " ";
	}
}

