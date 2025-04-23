/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:39 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:40 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/A.hpp"
#include <iostream>

A::A(){
    std::cout << "Constructor A called" << std::endl;
}

A::~A(){
    std::cout << "Destructor A called" << std::endl;
}