/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:51:42 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/16 16:22:12 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	Zombie *zombies = new Zombie[N];
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return (zombies);
}