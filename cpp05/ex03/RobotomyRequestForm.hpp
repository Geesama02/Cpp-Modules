/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:31:01 by oait-laa          #+#    #+#             */
/*   Updated: 2025/05/26 11:34:45 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm& cpy);
        RobotomyRequestForm(std::string t);
        RobotomyRequestForm& operator=(RobotomyRequestForm& cpy);
        void execute(Bureaucrat const& executor) const;
        ~RobotomyRequestForm();
};

#endif