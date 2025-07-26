/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:23:21 by miafonso          #+#    #+#             */
/*   Updated: 2025/07/26 10:23:22 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <algorithm> // find
#define ERROR_MSG "Error"

template<typename T> 
typename T::iterator easyfind(T& container, int value){

    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return it;
    throw std::logic_error("No occurrence found");
    // Works with some containers, not all of them
    // for (size_t i = 0; i < container.size(); i++){
    //     if (container[i] == value)
    //         return static_cast<int>(i);
    // }
    // return -1;
}