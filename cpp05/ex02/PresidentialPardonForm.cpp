/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:56:50 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/26 13:04:39 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidentalPardon", false, 25, 5) {
    target = "Default_Target";
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& cpy) : AForm("presidentalPardon", false, 25, 5) {
    target = cpy.target;
}
PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("presidentalPardon", false, 25, 5) {
    target = t;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& cpy) {
    if (this != &cpy)
        target = cpy.target;
    return (*this);
}
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (getSign() == false)
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() {}