/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:08 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:08 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <string>

class Cure: public AMateria {
    private:
        std::string _type;
    public:
        Cure();
        Cure(std::string type);
        Cure(const Cure &copy);
        Cure &operator=(const Cure &src);
        ~Cure();

        void        use(ICharacter& target);
        AMateria*   clone() const;
};
