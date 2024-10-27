/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:38:56 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/27 09:42:43 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 0;
	int N = 5;
	Zombie *z1 = zombieHorde(N, "juwi");
	if (z1 == NULL)
		return (1);
	while (i < N)
	{
		z1[i].announce();
		i++;
	}
	delete[] z1;
	return (0);
}
