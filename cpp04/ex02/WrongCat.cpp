/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:21:09 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/11 11:21:35 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Default constructor called\n";
	type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& to_copy)
{
	std::cout << "WrongCat: Copy constructor called\n";
	type = to_copy.type;
}
WrongCat& WrongCat::operator=(const WrongCat& to_copy)
{
	std::cout << "WrongCat: Copy assignment operator called\n";
	if (this != &to_copy)
		this->type = to_copy.type;
	return (*this);
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called\n";
}
void WrongCat::makeSound() const
{
	std::cout << "Meow!\n";
}