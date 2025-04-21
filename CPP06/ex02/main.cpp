#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"
#include "include/Base.hpp"
#include <iostream>

int main(){
    Base* test = Base::generate();
    Base& ref = *test;

    Base::identify(test);
    Base::identify(ref);
}