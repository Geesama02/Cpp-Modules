/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:51:42 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/13 11:24:40 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	if (N <= 0)
	{
		std::cerr << "N must be positive!\n";
		return (NULL);
	}
	Zombie *zombies = new (std::nothrow)Zombie[N];
	if (!zombies) {
		std::cerr << "Failed memory allocation\n";
		return (NULL);
	}
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return (zombies);
}