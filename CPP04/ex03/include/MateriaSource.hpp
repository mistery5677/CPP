/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:17 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:17 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource: public IMateriaSource {
    private:
        AMateria *_inventory[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource &operator=(const MateriaSource& copy);
        ~MateriaSource();
        
        void        learnMateria(AMateria* materia);
        AMateria*   createMateria(std::string const & type);
};