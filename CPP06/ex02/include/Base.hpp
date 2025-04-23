/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:34 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:35 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Base {
    private:
    public:
        Base();
        virtual ~Base();

        static          Base* generate(void);
        static void     identify(Base* p);
        static void     identify(Base& p);
};