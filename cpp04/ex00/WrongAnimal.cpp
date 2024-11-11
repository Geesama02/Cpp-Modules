/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:18:24 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/11 11:18:46 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Default constructor called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& to_copy)
{
	std::cout << "WrongAnimal: Copy constructor called\n";
	type = to_copy.type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& to_copy)
{
	std::cout << "WrongAnimal: Copy assignment operator called\n";
	if (this != &to_copy)
		this->type = to_copy.type;
	return (*this);
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called\n";
}
std::string WrongAnimal::getType() const
{
	return (type);
}
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound!\n";
}