/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:48:43 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/17 14:10:14 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	std::string cmd;
	int index;
	int indexToView;
	PhoneBook my_phonebook;
	index = 0;
	while (cmd != "EXIT")
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT): ";
		std::cin >> cmd;
		if (std::cin.fail())
			return (0);
		if (cmd == "ADD")
		{
			if (my_phonebook.addContact(index))
				return (0);
			index++;
			if (index == 8)
				index = 0;
		}
		else if (cmd == "SEARCH")
		{
			indexToView = 0;
			my_phonebook.search();
			while (indexToView > 8 || indexToView < 1)
			{
				std::cout << "Enter Contact Index To View: ";
				std::cin >> indexToView;
				if (std::cin.eof())
					return (0);
				if (std::cin.fail())
					indexToView = 0;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (indexToView <= 8 && indexToView >= 1)
					my_phonebook.getContact(indexToView - 1).display();
				else
					std::cout << "Invalid Index!\n";
			}
		}
	}
	return (0);
}
