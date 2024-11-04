/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:08 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/04 11:54:43 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap p1("p1");
	ClapTrap p2("p2");

	p1.attack("p2");
	p1.attack("p2");
	p1.attack("p2");
	p1.attack("p2");
	p1.attack("p2");
	p1.attack("p2");
	p1.attack("p2");
	p1.attack("p2");
	p1.beRepaired(20);
	p1.takeDamage(15);
	p1.takeDamage(15);
	p1.takeDamage(15);
	p1.attack("p2");

	return (0);
}