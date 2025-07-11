/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:36:54 by oait-laa          #+#    #+#             */
/*   Updated: 2025/07/11 14:03:24 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2) {
            std::cerr << "Error: Invalid number of arguments!." << std::endl;
            return (1);
        }
        PmergeMe obj;
        obj.parse(argv);
        obj.mergeSort();
        return (0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}