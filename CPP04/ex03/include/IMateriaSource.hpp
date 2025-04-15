/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:14 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:14 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <string>

class IMateriaSource {
    public:
        virtual             ~IMateriaSource() {}
        virtual void        learnMateria(AMateria*) = 0;
        virtual AMateria*   createMateria(std::string const & type) = 0;
};