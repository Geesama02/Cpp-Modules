/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:16:01 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/25 10:15:05 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: Default constructor called\n";
	setName("unnamed");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}
ScavTrap::ScavTrap (std::string new_name) : ClapTrap(new_name)
{
	std::cout << "ScavTrap: Constructor with name called\n";
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}
ScavTrap::~ScavTrap ()
{
	std::cout << "ScavTrap: Destructor called\n";
}

ScavTrap::ScavTrap (const ScavTrap& to_copy) : ClapTrap(to_copy)
{
	std::cout << "ScavTrap: Copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& to_copy)
{
	std::cout << "ScavTrap: Copy assignment operator called\n";
	if (this != &to_copy)
		ClapTrap::operator=(to_copy);
	return (*this);
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " Now in Gate keeper mode!\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else if (getHitPoints() <= 0)
		std::cout << "ScavTrap " << getName() << ": Already Dead, Can't do anything!\n";
	else
		std::cout << "ScavTrap " << getName() << ": Not Enough Energy points!\n";
}