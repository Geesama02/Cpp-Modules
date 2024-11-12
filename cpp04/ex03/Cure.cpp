/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:19:09 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/12 14:20:36 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	type = "cure";
}
Cure::Cure(const Cure& to_copy)
{
	setType(to_copy.type);
}
Cure& Cure::operator=(const Cure& to_copy)
{
	if (this != &to_copy)
		setType(to_copy.type);
	return (*this);
}
Cure::~Cure() {}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
AMateria* Cure::clone() const
{
	AMateria *new_clone = new Cure();
	return (new_clone);
}