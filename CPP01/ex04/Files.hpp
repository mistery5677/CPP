/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Files.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:11:16 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/13 14:11:17 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Files
{
private:
    std::fstream myFile;
    std::fstream newFile;
    std::string target;
    std::string replace;
public:
    Files(std::string inFile, std::string outFile, std::string target, std::string replace);
    ~Files();
    void readFile();
};