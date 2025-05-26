/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:14:12 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/25 10:31:02 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm& cpy);
        ShrubberyCreationForm(std::string t);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& cpy);
        void execute(Bureaucrat const& executor) const;
        ~ShrubberyCreationForm();
};

#endif