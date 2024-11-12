/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:02:43 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/12 15:38:41 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "none";
}
AMateria::AMateria(std::string const & type)
{
	setType(type);
}
AMateria::AMateria(const AMateria& to_copy)
{
	setType(to_copy.type);
}
AMateria& AMateria::operator=(const AMateria& to_copy)
{
	if (this != &to_copy)
		setType(to_copy.type);
	return (*this);
}
AMateria::~AMateria() {}
void AMateria::setType(std::string const &new_type)
{
	type = new_type;
}
std::string const & AMateria::getType() const
{
	return (type);
}
void AMateria::use(ICharacter& target) { (void)target; }