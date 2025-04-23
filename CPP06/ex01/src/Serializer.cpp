/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:25 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:26 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include <stdint.h>
// #include <cstdint> c++11

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& copy){
	(void)copy;
}

Serializer& Serializer::operator=(const Serializer& src){
	(void) src;
	return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data *ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t ptr){
    return reinterpret_cast<Data*>(ptr);
}