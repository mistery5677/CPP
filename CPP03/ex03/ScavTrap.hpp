/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:26:10 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/04 14:49:34 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap{
    private:
        bool    _guardMode;
    public:
        ScavTrap();
        ScavTrap(ClapTrap clapTrap);
        ScavTrap(const ScavTrap &copy);
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap &other);

        void    attack(const std::string& target);
        void    guardGate();
};