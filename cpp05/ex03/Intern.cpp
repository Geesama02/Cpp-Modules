/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:40:03 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/26 17:07:03 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char* Intern::FormDoesntExist::what() const throw() {
    return ((msg).c_str());
}
Intern::FormDoesntExist::FormDoesntExist(std::string& n) : msg(n + " form doesn't exist!") {}
Intern::FormDoesntExist::~FormDoesntExist() throw() {}
Intern::Intern() {}
Intern::Intern(Intern& cpy) {
    (void)cpy;
}
Intern& Intern::operator=(Intern& cpy) {
    (void)cpy;
    return (*this);
}
AForm* Intern::createShrubbery(std::string& target) {
    return (new ShrubberyCreationForm(target));
}
AForm* Intern::createRoboto(std::string& target) {
    return (new RobotomyRequestForm(target));
}
AForm* Intern::createPresidentialPardon(std::string& target) {
    return (new PresidentialPardonForm(target));
}
AForm* Intern::makeForm(std::string name, std::string target) {
    struct PairArray {
        std::string target;
        AForm* (Intern::*func)(std::string&);
    };
    PairArray arr[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRoboto},
        {"presidental pardon", &Intern::createPresidentialPardon}
    };
    int i = 0;
    while (i < 3) {
        if (name == arr[i].target) {
            AForm* form = (this->*(arr[i].func))(target);
            std::cout << "Intern creates " << *form << std::endl;
            return (form);
        }
        i++;
    }
    throw Intern::FormDoesntExist(name);
}
Intern::~Intern() {}