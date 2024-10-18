/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:48:12 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/17 12:19:27 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::search()
{
	int i = 0;
	std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "+----------+----------+----------+----------+\n";
	while (i < 8)
	{
		contacts[i].search(i + 1);
		std::cout << "+----------+----------+----------+----------+\n";
		i++;
	}
}

Contact PhoneBook::getContact(int index)
{
	return (contacts[index]);
}
int PhoneBook::addContact(int index)
{
	return (contacts[index].add());
}
