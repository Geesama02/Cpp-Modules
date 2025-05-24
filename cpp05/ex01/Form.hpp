/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:53:42 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/24 13:05:43 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
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
        Form();
        Form(Form& cpy);
        Form(const std::string& n, bool s, const int sG, const int eG);
        Form& operator=(Form& cpy);
        const std::string& getName() const;
        bool getSign() const;
        const int& getSignGrade() const;
        const int& getExecGrade() const;
        void beSigned(Bureaucrat& bureaucrat);
        ~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif

