/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:18:25 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/27 11:21:34 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade Too High!");
}
const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade Too Low!");
}
const char* AForm::FormNotSigned::what() const throw() {
    return ("Form is not Signed!");
}
const char* AForm::FileNotOpen::what() const throw() {
    return ("Error Opening File!");
}
AForm::AForm() : name("unnamed"), isSigned(false), signGrade(150), execGrade(150) {}
AForm::AForm(AForm& cpy) : name(cpy.name), isSigned(cpy.isSigned), signGrade(cpy.signGrade), execGrade(cpy.execGrade) {}
AForm::AForm(const std::string& n, bool s, const int sG, const int eG) : name(n), isSigned(s), signGrade(sG), execGrade(eG) {
    if (sG < 1 || eG < 1)
        throw AForm::GradeTooHighException();
    else if (eG > 150 || sG > 150)
        throw AForm::GradeTooLowException();
}
AForm& AForm::operator=(AForm& cpy) {
    if (this != &cpy)
        isSigned = cpy.isSigned;
    return (*this);
}
const std::string& AForm::getName() const {
    return (name);
}
bool AForm::getSign() const {
    return (isSigned);
}
const int& AForm::getSignGrade() const {
    return (signGrade);
}
const int& AForm::getExecGrade() const {
    return (execGrade);
}
void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();
}
AForm::~AForm() {}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
    os << obj.getName() << ", form grade required to sign " << obj.getSignGrade() << ", Grade required to execute it " << obj.getExecGrade() << '.';
    return (os);
}