/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:16:21 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:16:21 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Brain.hpp"

class Animal{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal &operator=(const Animal &src);
        virtual ~Animal();

        virtual void makeSound() const = 0;
        virtual std::string getType() const = 0;
        virtual std::string getIdea(int index) const = 0;
};