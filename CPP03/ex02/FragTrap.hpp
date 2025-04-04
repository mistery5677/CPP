/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:26:02 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/04 14:26:02 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"

class FragTrap: public ClapTrap{
    private:

    public:
        FragTrap();
        FragTrap(ClapTrap clapTrap);
        FragTrap(const FragTrap &copy);
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap& operator=(const FragTrap &src);

        void    attack(const std::string& target);
        void    highFivesGuys(void);
};