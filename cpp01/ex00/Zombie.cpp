/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:39:49 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/16 15:34:12 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::getName()
{
	return (name);
}
void Zombie::setName(std::string newName)
{
	name = newName;
}
void Zombie::announce()
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}
Zombie::Zombie( std::string name )
{
	setName(name);
}
Zombie::~Zombie()
{
	std::cout << getName() << ": Byyyyye BraiiiiiiinnnzzzZ...\n";
}