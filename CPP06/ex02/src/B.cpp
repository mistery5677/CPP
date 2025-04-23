/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:41 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:42 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/B.hpp"
#include <iostream>

B::B(){
    std::cout << "Constructor B called" << std::endl;
}

B::~B(){
    std::cout << "Destructor B called" << std::endl;
}