/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:56:40 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 10:56:40 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    private:
        std::string _type;  
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &src);
        ~WrongCat();

        void makeSound() const;
        std::string getType() const;
};