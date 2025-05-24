/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:09:46 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/24 13:15:39 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade Too High!");
}
const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade Too Low!");
}
Form::Form() : name("unnamed"), isSigned(false), signGrade(150), execGrade(150) {}
Form::Form(Form& cpy) : name(cpy.name), isSigned(cpy.isSigned), signGrade(cpy.signGrade), execGrade(cpy.execGrade) {}
Form::Form(const std::string& n, bool s, const int sG, const int eG) : name(n), isSigned(s), signGrade(sG), execGrade(eG) {
    if (sG < 1 || eG < 1)
        throw Form::GradeTooHighException();
    else if (eG > 150 || sG > 150)
        throw Form::GradeTooLowException();
}
Form& Form::operator=(Form& cpy) {
    (void)cpy;
    return (*this);
}
const std::string& Form::getName() const {
    return (name);
}
bool Form::getSign() const {
    return (isSigned);
}
const int& Form::getSignGrade() const {
    return (signGrade);
}
const int& Form::getExecGrade() const {
    return (execGrade);
}
void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade)
        isSigned = true;
    else
        throw Form::GradeTooLowException();
}
Form::~Form() {}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
    os << obj.getName() << ", form grade required to sign " << obj.getSignGrade() << ", Grade required to execute it " << obj.getExecGrade() << '.';
    return (os);
}