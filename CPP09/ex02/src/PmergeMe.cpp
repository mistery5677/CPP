#include "../include/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(char** argv)
{
	BuildContainers(argv); // Builds the containers
}

PmergeMe::PmergeMe(const PmergeMe& cpy){
    this->_main = cpy._main;
    this->_pend = cpy._pend;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy){
    if (this != &cpy){
        this->_main = cpy._main;
        this->_pend = cpy._pend;
    }

	return *this;
}

PmergeMe::~PmergeMe(){
}


int CountNumbers(char** numbers)
{
	int count = 0;

	for (int i = 0; numbers[i]; i++)
		count++;

	std::cout << "We have " << count << " numbers" << std::endl;
	return count;
}

/// Builds the containers according to the numbers that the user gave
void PmergeMe::BuildContainers(char** numbers)
{
	for (int i = 1; numbers[i]; i += 2)
	{
		int first = std::atoi(numbers[i]);
		int second = std::atoi(numbers[i + 1]);
		std::cout << "Comparar: " << numbers[i] << " com " << numbers[i + 1] << std::endl;
		
		if (first > second)
		{
			_main.push_back(first);
			_pend.push_back(second);
		}

		else
		{
			_main.push_back(second);
			_pend.push_back(first);
		}
	}
}

std::vector<int> PmergeMe::GetVector()
{
	return _main;
}

std::deque<int> PmergeMe::GetDeque()
{
	return _pend;
}