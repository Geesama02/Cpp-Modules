/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:21:35 by oait-laa          #+#    #+#             */
/*   Updated: 2025/06/02 10:10:15 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> ints;
    ints.push_back(0);
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);
    std::vector<int>::iterator it = easyfind(ints, 1);
    if (it == ints.end())
        std::cout << "Not Found!" << std::endl;
    else {
        std::cout << "Found!" << std::endl;
    }
    return (0);
}