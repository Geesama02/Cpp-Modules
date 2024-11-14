/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:17:28 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/13 12:26:45 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
Harl::Harl()
{
	debugPtr = &Harl::debug;
	infoPtr = &Harl::info;
	warningPtr = &Harl::warning;
	errorPtr = &Harl::error;
}

void Harl::complain( std::string level )
{
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4)
	{
		if (arr[i] == level)
			break;
		i++;
	}
	switch (i) {
		case 0:
			(this->*debugPtr)();
			break;
		case 1:
			(this->*infoPtr)();
			break;
		case 2:
			(this->*warningPtr)();
			break;
		case 3:
			(this->*errorPtr)();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}