/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:06:33 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/21 14:17:55 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl my_harl;
	
	my_harl.complain("DEBUG");
	my_harl.complain("INFO");
	my_harl.complain("WARNING");
	my_harl.complain("ERROR");
	my_harl.complain("BLABLA");
	return (0);
}