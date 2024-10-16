/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:38:56 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/16 15:46:26 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z1 = newZombie("zombie1");
	Zombie *z2 = newZombie("zombie2");
	z1->announce();
	z2->announce();
	randomChump("zombie3");
	delete z1;
	Zombie *z4 = newZombie("zombie4");
	z4->announce();
	delete z2;
	delete z4;
	return (0);
}
