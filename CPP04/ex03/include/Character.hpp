/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:06 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:06 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character: public ICharacter{
    private:
        std::string _name;
        AMateria    *_inventory[4];
        struct Floor {
            AMateria* materia;
            Floor* next;
        };
        Floor* _floor;
    public:
        Character();
        Character(std::string name);
        Character(const Character& copy);
        Character &operator=(const Character& copy);
        ~Character();

        std::string const & getName() const;
        void        equip(AMateria* m);
        void        unequip(int idx);
        void        use(int idx, ICharacter& target);
        void        checkInventory();
};