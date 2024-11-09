/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:08 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/09 11:15:36 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d1("tst");
	FragTrap f1;
	ScavTrap s1;

	d1.whoAmI();
	d1.attack("enemy");
	d1.highFivesGuys();
	d1.guardGate();
	std::cout << "Hit Point -> " << d1.getHitPoints() << " | FragTrap Hit Point -> " << f1.getHitPoints() << '\n';
	std::cout << "Energy points -> " << d1.getEnergyPoints() << " | ScavTrap Energy points -> " << s1.getEnergyPoints() << '\n';
	std::cout << "Attack damage -> " << d1.getAttackDamage() << " | FragTrap Attack damage -> " << s1.getAttackDamage() << '\n';

	return (0);
}