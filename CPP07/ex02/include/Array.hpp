/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:46:43 by mistery576        #+#    #+#             */
/*   Updated: 2025/04/23 21:46:44 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T> class Array{
    private:
        T       *_data;
        int     _size;
        
    public:
        Array();
        Array(unsigned int n);
        Array(Array<T>& copy);
        Array&      operator=(Array<T>& src);
        T&          operator[](int index);
        ~Array();
        
        int         size() const;
        void        printData();
};

// #include "../src/Array.tpp"