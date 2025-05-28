/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:37:52 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/28 09:23:31 by oait-laa         ###   ########.fr       */
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
        AForm* rrf4;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Shrubbery");
        delete rrf;
        rrf2 = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf2;
        rrf3 = someRandomIntern.makeForm("presidental pardon", "President");
        delete rrf3;
        rrf4 = someRandomIntern.makeForm("random", "President");
        delete rrf4;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}