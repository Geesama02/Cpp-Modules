/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:59:29 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/23 16:15:05 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& n, int g);
        Bureaucrat(Bureaucrat& cpy);
        Bureaucrat& operator=(Bureaucrat& cpy);
        const std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        ~Bureaucrat();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif