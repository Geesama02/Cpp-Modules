/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:27:47 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/11 14:31:14 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called\n";
}
Brain::Brain(const Brain& to_copy)
{
	int i = 0;
	std::cout << "Brain: Copy constructor called\n";
	while(i < 100)
	{
		ideas[i] = to_copy.ideas[i];
		i++;
	}
}
Brain& Brain::operator=(const Brain& to_copy)
{
	int i = 0;
	std::cout << "Brain: Copy assignment operator called\n";
	if (this != &to_copy)
	{
		while(i < 100)
		{
			this->ideas[i] = to_copy.ideas[i];
			i++;
		}
	}
	return (*this);
}
Brain::~Brain()
{
	std::cout << "Brain: Destructor called\n";
}