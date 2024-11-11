/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:25:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/11 11:13:48 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: Default constructor called\n";
}
Animal::Animal(const Animal& to_copy)
{
	std::cout << "Animal: Copy constructor called\n";
	type = to_copy.type;
}
Animal& Animal::operator=(const Animal& to_copy)
{
	std::cout << "Animal: Copy assignment operator called\n";
	if (this != &to_copy)
		this->type = to_copy.type;
	return (*this);
}
Animal::~Animal()
{
	std::cout << "Animal: Destructor called\n";
}
std::string Animal::getType() const
{
	return (type);
}
void Animal::makeSound() const
{
	std::cout << "Animal Sound!\n";
}