#include "include/MutantStack.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{

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

    //[...]
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
    std::stack<int> s(mstack);
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