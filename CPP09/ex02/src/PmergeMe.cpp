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
bool PmergeMe::insertNumbers(int argc, char **argv){
	// Validate all the numbers in the arguments
	for (int x = 1; argv[x]; x++){
		if (argv[x][0] == '\0')
		{
			std::cerr << "Error: Empty string in input" << std::endl;
			return false;
		}
		for (int y = 0; argv[x][y]; y++){
			if (argv[x][y] < '0' || argv[x][y] >'9'){
				std::cerr << "Error: FOUND AN INVALID NUMBER" << std::endl;
				return false;
			}
		}
	}

	char* vectorEnd;
	char* dequeEnd;

	// Pass all the numbers to each container
	for (int x = 1; x < argc; x++){
		_vector.push_back(std::strtol(argv[x], &vectorEnd, 10));
		_deque.push_back(std::strtol(argv[x], &dequeEnd, 10));
	}

	if (_vector.size() == 1)
	{
		std::cerr << "Error: Only one member, its useless to sort" << std::endl;
		return false;
	}
	return true;
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

// Helper function to merge numbers
template <typename Container>
void mergePairs(Container &pairs, size_t left, size_t mid, size_t right) {
    Container temp;
    size_t i = left;
    size_t j = mid + 1;

    while (i <= mid && j <= right) {
        if (pairs[i].big <= pairs[j].big) {
            temp.push_back(pairs[i++]);
        } else {
            temp.push_back(pairs[j++]);
        }
    }

    while (i <= mid) temp.push_back(pairs[i++]);
    while (j <= right) temp.push_back(pairs[j++]);

    for (size_t k = 0; k < temp.size(); k++) {
        pairs[left + k] = temp[k];
    }
}

// Recursive sorting
template <typename Container>
void recursiveSortPairs(Container &pairs, size_t left, size_t right) {
    if (left >= right) return;

    size_t mid = left + (right - left) / 2;

    recursiveSortPairs(pairs, left, mid);
    recursiveSortPairs(pairs, mid + 1, right);
    mergePairs(pairs, left, mid, right);
}

template <typename Container>
size_t findBigPos(const Container &chain, long big)
{
    for (size_t i = 0; i < chain.size(); i++)
    {
        if (chain[i] == big)
            return i;
    }
    return chain.size();
}

template <typename Container>
void binaryInsert(Container &chain, long value, size_t maxPos) {
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
        typename ChainContainer::iterator it = std::find(mainChain.begin(), mainChain.end(), pairs[idx].big);
        size_t maxPos = std::distance(mainChain.begin(), it);
        binaryInsert(mainChain, pairs[idx].small, maxPos);
    }
}


/// @brief Sorts the vector
void orderVector(std::vector<long> &vectorToSort){
	std::vector<Pair> pairs;
	bool isOdd = false;
	long extraNumber;
	
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
	if (pairs.size() > 1) {
		recursiveSortPairs(pairs, 0, pairs.size() - 1);
	}

	// Create the main chain
	std::vector<long> mainChain;
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
void orderDeque(std::deque<long> &vectorToSort){
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
	if (pairs.size() > 1) {
    	recursiveSortPairs(pairs, 0, pairs.size() - 1);
	}

	// Create the main chain
	std::deque<long> mainChain;
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