/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:08 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/07 11:05:40 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap s1;
	ScavTrap s2(s1);
	ScavTrap s3("ls");

	// s1 = s3;
	std::cout << s1.getName() << '\n';
	s1.guardGate();
	s1.attack("test1");
	s1.beRepaired(20);

	return (0);
}