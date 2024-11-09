/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:08 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/07 11:48:27 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap s1;
	ScavTrap s2(s1);
	ScavTrap s3("test1");
	FragTrap s4("s4");

	s1 = s3;
	std::cout << s1.getName() << '\n';
	s1.guardGate();
	s1.attack("test2");
	s1.beRepaired(20);
	s4.highFivesGuys();
	s4.beRepaired(20);
	std::cout << s4.getHitPoints() << '\n';
	s4.takeDamage(500);
	s4.takeDamage(500);

	return (0);
}