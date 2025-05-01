#pragma once
#include <deque>
#include <vector>

class PmergeMe{
    private:
        std::deque<int>     _pend;
        std::vector<int>    _main;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& cpy);
        PmergeMe& operator=(const PmergeMe& cpy);
        ~PmergeMe();
}
