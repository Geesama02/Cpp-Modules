/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:10:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/28 17:11:06 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria* Character::dropped_inventory[1024] = { NULL };

Character::Character()
{
	name = "no_name";
	int i = 0;
	slots = new AMateria*[4];
	while (i < 4)
	{
		slots[i] = NULL;
		i++;
	}
}
Character::Character(std::string new_name)
{
	name = new_name;
	int i = 0;
	slots = new AMateria*[4];
	while (i < 4)
	{
		slots[i] = NULL;
		i++;
	}
}
Character::Character(const Character& to_copy)
{
	name = to_copy.name;
	int i = 0;
	slots = new AMateria*[4];
	while(i < 4)
	{
		if (slots[i] != NULL)
			slots[i] = to_copy.slots[i]->clone();
		else
			slots[i] = NULL;
		i++;
	}
}
Character& Character::operator=(const Character& to_copy)
{
	if (this != &to_copy)
	{
		name = to_copy.name;
		int i = 0;
		while(i < 4)
		{
			if (slots[i] != NULL)
			{
				delete slots[i];
				slots[i] = to_copy.slots[i]->clone();
			}
			else
				slots[i] = NULL;
			i++;
		}
	}
	return (*this);
}
Character::~Character()
{
	int i = 0;
	while(i < 4)
	{
		delete slots[i];
		i++;
	}
	delete[] slots;
}
std::string const & Character::getName() const
{
	return (name);
}
void Character::equip(AMateria* m)
{
	if (m->check_if_equipped())
	{
		std::cout << "Materia Already equipped!\n";
		return;
	}
	int i = 0;
	while (i < 4)
	{
		if (slots[i] == NULL)
		{
			m->change_equip_state(true);
			slots[i] = m;
			return;
		}
		i++;
	}
}
void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && slots[idx] == NULL)
		std::cout << "Inventory space is already empty!\n";
	else if (idx < 4 && idx >= 0)
	{
		int i = 0;
		while (i < 1024)
		{
			if (dropped_inventory[i] == NULL)
			{
				dropped_inventory[i] = slots[idx];
				break;
			}
			i++;
		}
		slots[idx]->change_equip_state(false);
		slots[idx] = NULL;
	}
	else
		std::cout << "Invalid Inventory id!\n";
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && slots[idx] == NULL)
		std::cout << "Inventory space is empty!\n";
	else if (idx < 4 && idx >= 0)
		slots[idx]->use(target);
	else
		std::cout << "Invalid Inventory id!\n";
}

void Character::cleanFloor()
{
	int i = 0;
	while (i < 1024)
	{
		if (dropped_inventory[i] && dropped_inventory[i]->check_if_equipped() == false)
			delete dropped_inventory[i];
		i++;
	}
}