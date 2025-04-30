/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:46:30 by mistery576        #+#    #+#             */
/*   Updated: 2025/04/30 11:19:04 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// X -> address of an array;
// Y -> Lenght of the array;
// U -> Function to use in each value of the array

template <typename X, typename Y, typename Func> void iter(X *arr, Y lenght, Func func){
    if (!arr)
        return ;
    for (int i = 0; arr + i && i < lenght; i++)
        func(*(arr + i));
}