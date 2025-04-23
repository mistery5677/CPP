/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:46 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:47 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/C.hpp"
#include <iostream>

C::C(){
    std::cout << "Constructor C called" << std::endl;
}

C::~C(){
    std::cout << "Destructor C called" << std::endl;
}