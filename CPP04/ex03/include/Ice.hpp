/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:10 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:10 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice: public AMateria {
    private:
        std::string _type;
    public:
        Ice();
        Ice(std::string type);
        Ice(const Ice &copy);
        Ice &operator=(const Ice &src);
        ~Ice();

        void        use(ICharacter& target);
        AMateria*   clone() const;
};