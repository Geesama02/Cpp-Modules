/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:32:29 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/12 14:27:07 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
}
Ice::Ice(const Ice& to_copy)
{
	setType(to_copy.type);
}
Ice& Ice::operator=(const Ice& to_copy)
{
	if (this != &to_copy)
		setType(to_copy.type);
	return (*this);
}
Ice::~Ice() {}
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
AMateria* Ice::clone() const
{
	AMateria *new_clone = new Ice();
	return (new_clone);
}