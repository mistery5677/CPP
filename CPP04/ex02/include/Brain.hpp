/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:16:24 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:16:24 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain{
    private:
    
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &src);
        virtual ~Brain();
        
        std::string *_ideas;
};