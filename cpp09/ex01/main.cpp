/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sama <sama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:36:54 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/18 14:58:52 by sama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2) {
            
            std::cerr << "Error: Invalid number of arguments!." << std::endl;
            return (1);
        }
        RPN calculator;
        calculator.calculate(argv[1]);
        return (0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}