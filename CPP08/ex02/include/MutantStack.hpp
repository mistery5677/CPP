#pragma once
#include <stack>
#include <deque>

template<typename T>
class MutantStack: public std::stack<T>{
    private:

    public:
        MutantStack();
        MutantStack(const MutantStack& copy);
        MutantStack& operator=(const MutantStack& src);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "../src/MutantStack.tpp"