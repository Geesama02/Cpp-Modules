/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:08 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/24 11:44:28 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap p1("p1");

	p1.attack("p2");
	std::cout << "Energy Points : " << p1.getEnergyPoints() << std::endl;
	std::cout << "Health : " << p1.getHitPoints() << std::endl;
	p1.beRepaired(20);
	std::cout << "Health : " << p1.getHitPoints() << std::endl;
	p1.takeDamage(15);
	std::cout << "Health : " << p1.getHitPoints() << std::endl;
	p1.takeDamage(15);
	p1.takeDamage(15);
	p1.attack("p2");

	return (0);
}