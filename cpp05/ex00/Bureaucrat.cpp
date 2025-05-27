/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:43:15 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/27 10:47:15 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade Too High!");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade Too Low!");
}

Bureaucrat::Bureaucrat() : name("unnamed"), grade(150) {}
Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n) {
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = g;
}
Bureaucrat::Bureaucrat(Bureaucrat& cpy) : name(cpy.name), grade(cpy.grade) {}
Bureaucrat& Bureaucrat::operator=(Bureaucrat& cpy) {
    if (this != &cpy)
        grade = cpy.grade;
    return (*this);
}
const std::string Bureaucrat::getName() const {
    return (name);
}
int Bureaucrat::getGrade() const {
    return (grade);
}
void Bureaucrat::increment() {
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException();
}
void Bureaucrat::decrement() {
    if (grade < 150)
        grade++;
    else
        throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (os);
}