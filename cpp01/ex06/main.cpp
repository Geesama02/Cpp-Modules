/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:06:33 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/21 15:32:32 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl my_harl;

	switch (argc) {
		case 1:
			std::cout << "[ Missing The Complain?! ]\n";
			break;
		case 2:
			my_harl.complain(argv[1]);
			break;
		default:
			std::cout << "[ Too Many Complains! ]\n";
	}
	return (0);
}