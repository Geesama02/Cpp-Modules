/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:37:52 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/24 13:29:09 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try
    {
        Bureaucrat b1;
        std::cout  << b1 << "\n";
        Bureaucrat b2("b2", 3);
        std::cout << "Before Increment: \n" << b2 << "\n";
        b2.increment();
        std::cout << "After Increment: \n" << b2 << "\n";
        std::cout << "Before Decrement: \n" << b2 << "\n";
        b2.decrement();
        std::cout << "After Decrement: \n" << b2 << "\n";
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}