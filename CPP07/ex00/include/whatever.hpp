/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:46:20 by mistery576        #+#    #+#             */
/*   Updated: 2025/04/28 10:48:36 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void swap(T &a1, T &a2){
    T temp;
    temp = a1;
    a1 = a2;
    a2 = temp;
}

template <typename U> U& min(U &a1, U &a2){
    std::cout << "Min value between: " << a1 << " and " << a2 <<std::endl;
    
    if (a2 <= a1){
        std::cout << "Min value is " << a2 << std::endl;
        return a2;
    }
    std::cout << "Min value is " << a1 << std::endl;
    return a1;
}

template <typename J> J& max(J &a1, J &a2){
    std::cout << "Max value between: " << a1 << " and " << a2 <<std::endl;
    
	if (a2 >= a1){
        std::cout << "Max value is " << a2 << std::endl;
        return a2;
    }
    std::cout << "Max value is " << a1 << std::endl;
    return a1;
}
