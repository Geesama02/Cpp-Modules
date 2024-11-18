/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:38:56 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/18 12:19:57 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z1 = newZombie("zombie1");
	if (!z1)
		return (1);
	Zombie *z2 = newZombie("zombie2");
	if (!z2)
	{
		delete z1;
		return (1);
	}
	z1->announce();
	z2->announce();
	randomChump("zombie3");
	delete z1;
	delete z2;
	Zombie *z4 = newZombie("zombie4");
	if (!z4)
		return (1);
	z4->announce();
	delete z4;
	return (0);
}
