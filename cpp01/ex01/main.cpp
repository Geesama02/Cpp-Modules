/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:38:56 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/16 16:17:26 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z1 = zombieHorde(5, "da7mad");
	z1->announce();
	(z1 + 1)->announce();
	z1++;
	z1->announce();
	return (0);
}
