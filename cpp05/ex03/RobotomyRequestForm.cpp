/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:32:22 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/26 16:07:03 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", false, 72, 45) {
    target = "Default_Target";
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& cpy) : AForm("robotomy request", false, 72, 45) {
    target = cpy.target;
}
RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("robotomy request", false, 72, 45) {
    target = t;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& cpy) {
    if (this != &cpy) 
        target = cpy.target;
    return (*this);
}
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (getSign() == false)
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << "*Drilling Noises*" << std::endl;
    std::srand(time(NULL));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "robotomy failed." << std::endl;
    
}
RobotomyRequestForm::~RobotomyRequestForm() {}