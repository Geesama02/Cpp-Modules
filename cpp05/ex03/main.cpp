/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:37:52 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/26 17:05:07 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        AForm* rrf2;
        AForm* rrf3;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Shrubbery");
        rrf2 = someRandomIntern.makeForm("robotomy request", "Bender");
        rrf3 = someRandomIntern.makeForm("presidental vfsvfspardon", "President");
        delete rrf;
        delete rrf2;
        delete rrf3;
        // Bureaucrat b1("Bureaucrat1", 139);
        // Bureaucrat b2("Bureaucrat2", 40);
        // Bureaucrat b3("Bureaucrat3", 5);
        // AForm *f1 = new ShrubberyCreationForm("home");
        // AForm *f2 = new RobotomyRequestForm("home");
        // AForm *f3 = new PresidentialPardonForm("home");
        // std::cout << "====================================\n";
        // b1.signForm(*f1);
        // b1.executeForm(*f1);
        // std::cout << "====================================\n";
        // b2.signForm(*f2);
        // b2.executeForm(*f2);
        // std::cout << "====================================\n";
        // b3.signForm(*f3);
        // b3.executeForm(*f3);
        // std::cout << "====================================\n";
        // delete f1;
        // delete f2;
        // delete f3;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}