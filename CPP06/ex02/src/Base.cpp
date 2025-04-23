/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:44 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:45 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cmath>
#include <iostream>

Base::Base(){
    std::cout << "Called Base constructor" << std::endl;
}


Base::~Base(){
    std::cout << "Called Base desconstructor" << std::endl;
}

Base* Base::generate(void){
	srand (time(NULL));
    int randomNumber = rand() % 3;

    switch (randomNumber){
        case 0:
            return new A();
            break;
        case 1:
            return new B();
            break;
        case 2:
            return new C();
            break;
        default:
            return NULL;
    }
    return NULL;
}

void Base::identify(Base* p){
    if(dynamic_cast<A*>(p))
        std::cout << "P type is A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "P type is B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "P type is C" << std::endl;
}

void Base::identify(Base& p){

    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "P type reference is A" << std::endl;
    }catch(...) {};

    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "P type reference is B" << std::endl;
    }catch(...) {};

    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "P type reference is C" << std::endl;
    }catch(...) {};

}