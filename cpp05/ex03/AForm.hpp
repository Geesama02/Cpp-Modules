/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:12:29 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/27 11:38:59 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSigned : public std::exception {
            public:
                virtual const char* what() const throw();
        };
                class FileNotOpen : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        AForm();
        AForm(AForm& cpy);
        AForm(const std::string& n, bool s, const int sG, const int eG);
        AForm& operator=(AForm& cpy);
        const std::string& getName() const;
        bool getSign() const;
        const int& getSignGrade() const;
        const int& getExecGrade() const;
        void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const& executor) const = 0;
        virtual ~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif