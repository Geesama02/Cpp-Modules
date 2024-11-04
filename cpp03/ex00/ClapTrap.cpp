/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:21:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/04 11:55:11 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

std::string ClapTrap::getName() { return (name); }
int ClapTrap::getHitPoints() { return (hit_points); }
int ClapTrap::getEnergyPoints() { return (energy_points); }
int ClapTrap::getAttackDamage() { return (attack_damage); }
void ClapTrap::setName(std::string newName) { name = newName; }
void ClapTrap::setHitPoints(int HitPoints) { hit_points = HitPoints; }
void ClapTrap::setEnergyPoints(int EnergyPoints) { energy_points = EnergyPoints; }
void ClapTrap::setAttackDamage(int AttackDamage) { attack_damage = AttackDamage; }

ClapTrap::ClapTrap(std::string new_name)
{
	std::cout << "Default constructor called\n";
	setName(new_name);
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
}
ClapTrap::ClapTrap(const ClapTrap& to_copy)
{
	std::cout << "Copy constructor called\n";
	setName(to_copy.name);
	setHitPoints(to_copy.hit_points);
	setEnergyPoints(to_copy.energy_points);
	setAttackDamage(to_copy.attack_damage);
}
ClapTrap& ClapTrap::operator=(const ClapTrap& to_copy)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &to_copy)
	{
		setName(to_copy.name);
		setHitPoints(to_copy.hit_points);
		setEnergyPoints(to_copy.energy_points);
		setAttackDamage(to_copy.attack_damage);
	}
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << getName() << ": is Dead, Can't do anything!\n";
	else
		std::cout << "ClapTrap " << getName() << ": Not Enough Energy points!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << getName() << " has taken " << amount << " damage points!\n";
		setHitPoints(getHitPoints() - amount);
	}
	else
		std::cout << "ClapTrap " << getName() << ": Already Dead!\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << getName() << " healed " << amount << " points of Health!\n";
		setEnergyPoints(getEnergyPoints() - 1);
		setHitPoints(getHitPoints() + amount);
	}
	else if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << getName() << ": is Dead, Can't do anything!\n";
	else
		std::cout << "ClapTrap " << getName() << ": Not Enough Energy points!\n";
}