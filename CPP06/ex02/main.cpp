/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:49 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:50 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	delete test;
}