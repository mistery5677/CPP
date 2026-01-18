#include "../include/PmergeMe.hpp"
#include <sys/time.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

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

Pair::Pair(){
	small = 0;
	big = 0;
}

Pair::~Pair(){
}

Pair::Pair(const Pair& cpy){
    this->small = cpy.small;
    this->big = cpy.big;
}

Pair& Pair::operator=(const Pair& cpy){
    if (this != &cpy){
        this->small = cpy.small;
        this->big = cpy.big;
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

void PmergeMe::printAfter(){
	std::cout << "After: ";
	for (size_t x = 0; x < _vector.size(); x++)
		std::cout << _vector[x] << " ";
	std::cout << std::endl;
}

void PmergeMe::printBefore(int argc, char **argv){
	std::cout << "Before: ";
	for (int x = 1; x < argc; x++){
		std::cout << argv[x] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTimeToSort(int type, double time, size_t ctrSize){
	std::cout << std::fixed << std::setprecision(5);
	switch(type){
		case VECTOR:
			std::cout << "Time to process a range of " << ctrSize << " elements with std::vector : " << std::setprecision(5) << time << " us" << std::endl;
			break;
		case DEQUE:
			std::cout << "Time to process a range of " << ctrSize << " elements with std::deque : " << std::setprecision(5) << time << " us" << std::endl;
			break;
		default:
			break;
	}
}

template <typename Container>
void sortPairsByBig(Container &pairs){
	for (size_t i = 1; i < pairs.size(); i++){
		Pair key = pairs[i];
		size_t j = i;

		while(j > 0 && pairs[j - 1].big > key.big){
			pairs[j] = pairs[j - 1];
			j--;
		}
		pairs[j] = key;
	}
}

template <typename Container>
size_t findBigPos(const Container &chain, int big)
{
    for (size_t i = 0; i < chain.size(); i++)
    {
        if (chain[i] == big)
            return i;
    }
    return chain.size();
}

template <typename Container>
void binaryInsert(Container &chain, int value, size_t maxPos) {
    size_t left = 0;
    size_t right = maxPos;

    while (left < right) {
        size_t mid = (left + right) / 2;
        if (value < chain[mid])
            right = mid;
        else
            left = mid + 1;
    }
    chain.insert(chain.begin() + left, value);
}

template <typename PairContainer, typename ChainContainer>
void sortPairsBySmall(PairContainer &pairs, ChainContainer &mainChain)
{
    ChainContainer insertionOrder;

    size_t prev = 1;
    size_t curr = 3;

    while (prev < pairs.size())
    {
        size_t limit = curr < pairs.size() ? curr : pairs.size();
        for (size_t i = limit; i > prev; i--)
            insertionOrder.push_back(i - 1);
        prev = curr;
        curr = curr + 2 * prev;
    }

    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        size_t idx = insertionOrder[i];
        size_t maxPos = findBigPos(mainChain, pairs[idx].big);
        binaryInsert(mainChain, pairs[idx].small, maxPos);
    }
}


/// @brief Sorts the vector
void orderVector(std::vector<int> &vectorToSort){
	std::vector<Pair> pairs;
	bool isOdd = false;
	int extraNumber;
	
	for (size_t i = 0; i + 1 < vectorToSort.size(); i += 2){
		Pair currentPair;
		if (vectorToSort[i] < vectorToSort[i + 1]){
			currentPair.small = vectorToSort[i];
			currentPair.big = vectorToSort[i + 1];
		}

		else {
			currentPair.small = vectorToSort[i + 1];
			currentPair.big = vectorToSort[i];
		}
		pairs.push_back(currentPair);
	}
	if (vectorToSort.size() % 2 != 0){
		isOdd = true;
		extraNumber = vectorToSort.back();
	}

	// Sort pairs by big numbers
	sortPairsByBig(pairs);

	// Create the main chain
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].big);

	binaryInsert(mainChain, pairs[0].small, 0);

	sortPairsBySmall(pairs, mainChain);

	// Insert the extra number
	if (isOdd)
		binaryInsert(mainChain, extraNumber, mainChain.size());
	
	vectorToSort = mainChain;
}

/// @brief Sorts the vector
void orderDeque(std::deque<int> &vectorToSort){
	std::deque<Pair> pairs;
	bool isOdd = false;
	int extraNumber;
	
	for (size_t i = 0; i + 1 < vectorToSort.size(); i += 2){
		Pair currentPair;
		if (vectorToSort[i] < vectorToSort[i + 1]){
			currentPair.small = vectorToSort[i];
			currentPair.big = vectorToSort[i + 1];
		}

		else {
			currentPair.small = vectorToSort[i + 1];
			currentPair.big = vectorToSort[i];
		}
		pairs.push_back(currentPair);
	}
	if (vectorToSort.size() % 2 != 0){
		isOdd = true;
		extraNumber = vectorToSort.back();
	}

	// Sort pairs by big numbers
	sortPairsByBig(pairs);

	// Create the main chain
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].big);

	binaryInsert(mainChain, pairs[0].small, 0);

	sortPairsBySmall(pairs, mainChain);

	// Insert the extra number
	if (isOdd)
		binaryInsert(mainChain, extraNumber, mainChain.size());
	
	vectorToSort = mainChain;
}

/// @brief Will start the time to sort the vector
/// @return Time wasted to sort the vector 
double PmergeMe::sortVector(){
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	orderVector(_vector);
	clock_gettime(CLOCK_MONOTONIC, &end);
	double diff_in_us = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
    
    return diff_in_us;
}

/// @brief Will start the time to sort the Deque
/// @return Time wasted to sort the deque
double PmergeMe::sortDeque(){
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	orderDeque(_deque);
	clock_gettime(CLOCK_MONOTONIC, &end);
	double diff_in_us = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
    
    return diff_in_us;
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

