/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:32:08 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/26 17:07:09 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    class FormDoesntExist : public std::exception {
        private:
            std::string msg;
        public:
            FormDoesntExist(std::string& n);
            virtual const char* what() const throw();
            virtual ~FormDoesntExist() throw();
    };
    private:
        AForm* createShrubbery(std::string& target);
        AForm* createRoboto(std::string& target);
        AForm* createPresidentialPardon(std::string& target);
    public:
        Intern();
        Intern(Intern& cpy);
        Intern& operator=(Intern& cpy);
        AForm* makeForm(std::string name, std::string target);
        ~Intern();
};

#endif