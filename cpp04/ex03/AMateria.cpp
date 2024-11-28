/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:02:43 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/28 16:44:11 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "none";
	is_equipped = false;
}
AMateria::AMateria(std::string const & type)
{
	setType(type);
	is_equipped = false;
}
AMateria::AMateria(const AMateria& to_copy)
{
	setType(to_copy.type);
	is_equipped = to_copy.is_equipped;
}
AMateria& AMateria::operator=(const AMateria& to_copy)
{
	if (this != &to_copy)
	{
		setType(to_copy.type);
		is_equipped = to_copy.is_equipped;
	}
	return (*this);
}
AMateria::~AMateria() {}
void AMateria::setType(std::string const &new_type)
{
	type = new_type;
}
void AMateria::change_equip_state(bool state)
{
	is_equipped = state;
}
bool AMateria::check_if_equipped()
{
	return (is_equipped);
}

std::string const & AMateria::getType() const
{
	return (type);
}
void AMateria::use(ICharacter& target) { (void)target; }