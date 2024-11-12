/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:37:20 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/11 16:10:59 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor called\n";
	type = "Cat";
	brain = new Brain();
}
Cat::Cat(const Cat& to_copy)
{
	std::cout << "Cat: Copy constructor called\n";
	type = to_copy.type;
	brain = new Brain();
	*brain = *to_copy.brain;
}
Cat& Cat::operator=(const Cat& to_copy)
{
	std::cout << "Cat: Copy assignment operator called\n";
	if (this != &to_copy)
	{
		this->type = to_copy.type;
		delete brain;
		this->brain = new Brain();
		*this->brain = *to_copy.brain;
	}
	return (*this);
}
Cat::~Cat()
{
	std::cout << "Cat: Destructor called\n";
	delete brain;
}
void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}