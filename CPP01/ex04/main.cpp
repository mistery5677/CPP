/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:11:12 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/13 14:17:20 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include "Files.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string extension = ".replace";
        std::string outfile = argv[1] + extension;
        std::ifstream checkOut(argv[1]);
        if (!checkOut.good())
        {
            std::cout << "Error trying to open the file" << std::endl;
            return 1;
        }
        Files files(argv[1], outfile, argv[2], argv[3]);

        files.readFile();
        files.~Files();
    }
    else
        std::cout << "Expeted input: <file name> <target> <replace>" << std::endl;
    return 1;
}