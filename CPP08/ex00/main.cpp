#include "include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <queue>

int main(){

    std::cout << "\033[1;31m";
    std::cout << "*******TESTING VECTOR*******\n" << std::endl;
    std::cout << "\033[1;0m";

    std::vector<int> mySet;
    mySet.push_back(0);
    mySet.push_back(10);
    mySet.push_back(5);   
    std::cout << "Found the value: " << *easyFind(mySet, 10) << std::endl; // We have to put * because the iterator is a pointer

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING DEQUE*******\n" << std::endl;
    std::cout << "\033[1;0m";

    std::deque<int> mySet2;
    mySet2.push_back(0);
    mySet2.push_back(10);
    mySet2.push_back(5);   
    std::cout << "Found the value: " << *easyFind(mySet2, 10) << std::endl;

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING SET*******\n" << std::endl;
    std::cout << "\033[1;0m";

    std::set<int> mySet3;
    mySet3.insert(0);
    mySet3.insert(10);
    mySet3.insert(5);   
    try {
        std::cout << "Found the value: " << *easyFind(mySet3, 90) << std::endl;
    } catch (std::exception &e) { 
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING LIST*******\n" << std::endl;
    std::cout << "\033[1;0m";

    std::list<int> mySet4;
    mySet4.push_back(0);
    mySet4.push_back(10);
    mySet4.push_back(5);   
    std::cout << "Found the value: " << *easyFind(mySet4, 10) << std::endl;

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING MULTISET*******\n" << std::endl;
    std::cout << "\033[1;0m";

    std::multiset<int> mySet5;
    mySet5.insert(0);
    mySet5.insert(10);
    mySet5.insert(5);   
    std::cout << "Found the value: " << *easyFind(mySet5, 10) << std::endl;
}