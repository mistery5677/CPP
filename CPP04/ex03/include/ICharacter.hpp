/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:12 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:12 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void        equip(AMateria* m) = 0;
        virtual void        unequip(int idx) = 0;
        virtual void        use(int idx, ICharacter& target) = 0;
        
        virtual void        checkInventory() = 0;
};