/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:44:55 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/13 12:44:56 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>

class Zombie
{
private:
    std::string name; 
public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce(void);
};

#endif