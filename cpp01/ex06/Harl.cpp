/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:17:28 by oait-laa          #+#    #+#             */
/*   Updated: 2024/11/13 12:35:38 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}
void Harl::info( void )
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}
void Harl::warning( void )
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n\n";
}
void Harl::error( void )
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
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
			(this->*infoPtr)();
			(this->*warningPtr)();
			(this->*errorPtr)();
			break;
		case 1:
			(this->*infoPtr)();
			(this->*warningPtr)();
			(this->*errorPtr)();
			break;
		case 2:
			(this->*warningPtr)();
			(this->*errorPtr)();
			break;
		case 3:
			(this->*errorPtr)();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}