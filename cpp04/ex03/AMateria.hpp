/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:14:17 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/28 16:43:11 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
class ICharacter;

class AMateria
{
	protected:
		std::string type;
		bool is_equipped;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& to_copy);
		AMateria& operator=(const AMateria& to_copy);
		virtual ~AMateria();
		void setType(std::string const &new_type);
		void change_equip_state(bool state);
		bool check_if_equipped();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif