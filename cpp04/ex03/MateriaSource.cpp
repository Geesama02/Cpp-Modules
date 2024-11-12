/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:49:37 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/12 15:57:12 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int i = 0;
	slots = new AMateria*[4];
	while (i < 4)
	{
		slots[i] = NULL;
		i++;
	}
}
MateriaSource::MateriaSource(const MateriaSource& to_copy)
{
	int i = 0;
	while(i < 4)
	{
		delete slots[i];
		if (slots[i] != NULL)
			slots[i] = to_copy.slots[i]->clone();
		else
			slots[i] = NULL;
		i++;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& to_copy)
{
	if (this != &to_copy)
	{
		int i = 0;
		while(i < 4)
		{
			delete slots[i];
			if (slots[i] != NULL)
				slots[i] = to_copy.slots[i]->clone();
			else
				slots[i] = NULL;
			i++;
		}
	}
	return (*this);
}
MateriaSource::~MateriaSource()
{
	int i = 0;
	while(i < 4)
	{
		delete slots[i];
		i++;
	}
	delete[] slots;
}
void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia)
	{
		int i = 0;
		while(i < 4)
		{
			if (slots[i] == NULL)
			{
				slots[i] = materia;
				return;
			}
			i++;
		}
	}
	else
		std::cout << "Invalid Materia!\n";
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type != "ice" && type != "cure")
		return (0);
	int i = 0;
	while (i < 4)
	{
		if (slots[i] && slots[i]->getType() == type)
		{
			return (slots[i]->clone());
		}
		i++;
	}
	return (0);
}