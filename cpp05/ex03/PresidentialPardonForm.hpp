/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:55:50 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/26 12:56:30 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm& cpy);
        PresidentialPardonForm(std::string t);
        PresidentialPardonForm& operator=(PresidentialPardonForm& cpy);
        void execute(Bureaucrat const& executor) const;
        ~PresidentialPardonForm();
};

#endif