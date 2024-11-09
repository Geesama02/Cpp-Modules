/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:27:54 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/09 10:32:37 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: Default constructor called\n";
	setName("unnamed");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}
FragTrap::FragTrap (std::string new_name) : ClapTrap(new_name)
{
	std::cout << "FragTrap: Constructor with name called\n";
	setName(new_name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}
FragTrap::~FragTrap ()
{
	std::cout << "FragTrap: Destructor called\n";
}

FragTrap::FragTrap (const FragTrap& to_copy) : ClapTrap(to_copy)
{
	std::cout << "FragTrap: Copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& to_copy)
{
	std::cout << "FragTrap: Copy assignment operator called\n";
	if (this != &to_copy)
		ClapTrap::operator=(to_copy);
	return (*this);
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: High Five!\n";
}