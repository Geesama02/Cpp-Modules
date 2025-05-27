/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:37:52 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/27 11:01:34 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat b1("Bureaucrat1", 100);
        Bureaucrat b2("Bureaucrat2", 9);
        Form f1("Form1", false, 10, 15);
        b1.signForm(f1);
        b2.signForm(f1);
        std::cout << "Sign => " <<f1.getSign() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}