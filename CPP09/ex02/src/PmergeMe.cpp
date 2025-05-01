#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe& cpy){
    this->_main = cpy._main;
    this->_pend = cpy._pend;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy){
    if (this != cpy){
        this->_main = cpy._main;
        this->_pend = cpy._pend;
    }
}