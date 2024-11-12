/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:10:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/12 15:56:44 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	name = "no_name";
	int i = 0;
	slots = new AMateria*[4];
	while (i < 4)
	{
		slots[i] = nullptr;
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
		slots[i] = nullptr;
		i++;
	}
}
Character::Character(const Character& to_copy)
{
	name = to_copy.name;
	int i = 0;
	while(i < 4)
	{
		delete slots[i];
		if (slots[i] != nullptr)
			slots[i] = to_copy.slots[i]->clone();
		else
			slots[i] = nullptr;
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
			delete slots[i];
			if (slots[i] != nullptr)
				slots[i] = to_copy.slots[i]->clone();
			else
				slots[i] = nullptr;
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
	int i = 0;
	while (i < 4)
	{
		if (slots[i] == nullptr)
		{		
			slots[i] = m;
			return;
		}
		i++;
	}
}
void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && slots[idx] == nullptr)
		std::cout << "Inventory space is already empty!\n";
	else if (idx < 4 && idx >= 0)
		slots[idx] = nullptr;
	else
		std::cout << "Invalid Inventory id!\n";
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && slots[idx] == nullptr)
		std::cout << "Inventory space is empty!\n";
	else if (idx < 4 && idx >= 0)
		slots[idx]->use(target);
	else
		std::cout << "Invalid Inventory id!\n";
}