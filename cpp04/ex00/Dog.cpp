/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:07:52 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/11 11:08:18 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called\n";
	type = "Dog";
}
Dog::Dog(const Dog& to_copy)
{
	std::cout << "Dog: Copy constructor called\n";
	type = to_copy.type;
}
Dog& Dog::operator=(const Dog& to_copy)
{
	std::cout << "Dog: Copy assignment operator called\n";
	if (this != &to_copy)
		this->type = to_copy.type;
	return (*this);
}
Dog::~Dog()
{
	std::cout << "Dog: Destructor called\n";
}
void Dog::makeSound() const
{
	std::cout << "Woof Woof!\n";
}