#include "include/MutantStack.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>

int main()
{
    std::cout << "\033[1;32m";
    std::cout << "\n*******TESTING SUBJECT*******\n" << std::endl;
    std::cout << "\033[1;0m";
    std::stack<int> origStack;
    origStack.push(5);
    origStack.push(17);

    /////////////////////

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Mine: " << mstack.top() << " | Original: " << origStack.top() << std::endl;

    mstack.pop();
    origStack.pop();
    std::cout << "Mine: " << mstack.size() << " | Original: " << origStack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    origStack.push(3);
    origStack.push(5);
    origStack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();    
    ++it;
    --it;
    
    std::deque<int> origDeque;
    origDeque.push_back(5);
    origDeque.push_back(3);
    origDeque.push_back(5);
    origDeque.push_back(737);
    origDeque.push_back(0);
    std::deque<int>::iterator itd = origDeque.begin();
    // std::deque<int>::iterator ited = origDeque.end();
    ++itd;
    --itd;

    while (it != ite)
    {
        std::cout << "Mine: " << *it << " | Original: " << *itd << std::endl;
        ++it;
        ++itd;
    }

	std::cout << "Original start: " << *origDeque.begin() << " | Mine start: " << *mstack.begin() << std::endl;
	std::cout << "Original end: " << *origDeque.end() << " | Mine end: " << *mstack.end() << std::endl;

	std::cout << "\033[1;32m";
    std::cout << "\n*******TESTING LIST TYPE*******\n" << std::endl;
    std::cout << "\033[1;0m";
	
	std::list<int> origList;
    origList.push_back(5);
    origList.push_back(17);

    /////////////////////

    MutantStack<int> mstack2;
    mstack2.push(5);
    mstack2.push(17);

    std::cout << "Mine: " << mstack2.top() << " | Original: " << origList.back() << std::endl;

    mstack2.pop();
    origList.pop_back();
    std::cout << "Mine: " << mstack2.size() << " | Original: " << origList.size() << std::endl;
    mstack2.push(3);
    mstack2.push(5);
    mstack2.push(737);

    origList.push_back(3);
    origList.push_back(5);
    origList.push_back(737);

    MutantStack<int>::iterator it2 = mstack2.begin();
    MutantStack<int>::iterator ite2 = mstack2.end();    
    ++it2;
    --ite2;

	std::cout << "start: " << *it2 << " end: " << *ite2 << std::endl;
    return 0;
}

// int main(){
//     MutantStack<int> mstack;
//     mstack.push(5);
//     // std::cout << mstack.begin() << std::endl;
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     // MutantStack<int>::iterator ite = mstack.end();
//     // ++it;
//     // --it;
//     // while (it != ite)
//     // {
//     //     std::cout << *it << std::endl;
//     //     ++it;
//     // }


//     // std::stack<int> mstack;
//     // mstack.push(5);
//     // // std::cout << mstack.begin() << std::endl;
//     // std::stack<int>::iterator it = mstack.begin();
//     // std::stack<int>::iterator ite = mstack.end();
//     // ++it;
//     // --it;
//     // while (it != ite)
//     // {
//     //     std::cout << *it << std::endl;
//     //     ++it;
//     // }
// }