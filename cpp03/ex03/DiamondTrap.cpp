/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:13:54 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/09 11:07:44 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap () : ClapTrap("unnamed_clap_name")
{
	std::cout << "DiamondTrap: Default constructor called\n";
	name = "unnamed";
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}
DiamondTrap::DiamondTrap (std::string new_name) : ClapTrap(new_name + "_clap_name"), FragTrap(new_name + "_clap_name"), ScavTrap(new_name + "_clap_name")
{
	std::cout << "DiamondTrap: Constructor with name called\n";
	name = new_name;
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}
DiamondTrap::DiamondTrap (const DiamondTrap& to_copy)
{
	std::cout << "DiamondTrap: Copy constructor called\n";
	setName(to_copy.name);
	setHitPoints(to_copy.hit_points);
	setEnergyPoints(to_copy.energy_points);
	setAttackDamage(to_copy.attack_damage);
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& to_copy)
{
	std::cout << "DiamondTrap: Copy assignment operator called\n";
	if (this != &to_copy)
	{
		setName(to_copy.name);
		setHitPoints(to_copy.hit_points);
		setEnergyPoints(to_copy.energy_points);
		setAttackDamage(to_copy.attack_damage);
	}
	return (*this);
}
DiamondTrap::~DiamondTrap ()
{
	std::cout << "DiamondTrap: Destructor called\n";
}
void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name: " << name << " | ClapTrap's name: " << ClapTrap::getName() << '\n';
}