/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:37:52 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/27 11:28:07 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat b1("Bureaucrat1", 137);
        Bureaucrat b2("Bureaucrat2", 40);
        Bureaucrat b3("Bureaucrat3", 5);
        AForm *f1 = new ShrubberyCreationForm("home");
        AForm *f2 = new RobotomyRequestForm("home");
        AForm *f3 = new PresidentialPardonForm("home");
        std::cout << "====================================\n";
        b1.signForm(*f1);
        b1.executeForm(*f1);
        std::cout << "====================================\n";
        b2.signForm(*f2);
        b2.executeForm(*f2);
        std::cout << "====================================\n";
        b3.signForm(*f3);
        b3.executeForm(*f3);
        std::cout << "====================================\n";
        delete f1;
        delete f2;
        delete f3;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}