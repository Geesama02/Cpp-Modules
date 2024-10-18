/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:53:29 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/18 12:06:08 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	name = newName;
	myWeapon = NULL;
}
void	HumanB::attack()
{
	if (myWeapon)
		std::cout << name << " attacks with their " << (*myWeapon).getType() << '\n';
	else
		std::cout << name << " attacks with their " << "Hand (no Weapon)" << '\n';
}
void	HumanB::setWeapon(Weapon &newWeapon)
{
	myWeapon = &newWeapon;
}