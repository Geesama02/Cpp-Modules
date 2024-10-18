/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:48:50 by oait-laa          #+#    #+#             */
/*   Updated: 2024/10/17 12:22:21 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() { return (firstName); }
std::string Contact::getLastName() { return (lastName); }
std::string Contact::getNickname() { return (nickname); }
std::string Contact::getPhoneNum() { return (phoneNum); }
std::string Contact::getDarkSecret() { return (darkSecret); }
void Contact::setFirstName(std::string str) { firstName = str; }
void Contact::setLastName(std::string str) { lastName = str; }
void Contact::setNickname(std::string str) { nickname = str; }
void Contact::setPhoneNum(std::string str) { phoneNum = str; }
void Contact::setDarkSecret(std::string str) { darkSecret = str; }

int Contact::add()
{
	std::string tmp;
	std::cout << "Enter First Name: ";
	std::cin >> tmp;
	if (std::cin.fail())
		return (1);
	setFirstName(tmp);
	std::cout << "Enter Last Name: ";
	std::cin >> tmp;
	if (std::cin.fail())
		return (1);
	setLastName(tmp);
	std::cout << "Enter Nickname: ";
	std::cin >> tmp;
	if (std::cin.fail())
		return (1);
	setNickname(tmp);
	std::cout << "Enter Phone Number: ";
	std::cin >> tmp;
	if (std::cin.fail())
		return (1);
	setPhoneNum(tmp);
	std::cout << "Enter Darkest Secret: ";
	std::cin >> tmp;
	if (std::cin.fail())
		return (1);
	setDarkSecret(tmp);
	return (0);
}

std::string Contact::draw_line(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}
void Contact::display()
{
	if (getFirstName() == "")
	{
		std::cout << "Empty Contact Field!\n";
		return;
	}
	std::cout << "First Name: " << getFirstName() << '\n';
	std::cout << "Last Name: " << getLastName() << '\n';
	std::cout << "Nickname: " << getNickname() << '\n';
	std::cout << "Phone Number: " << getPhoneNum() << '\n';
	std::cout << "Darkest Secret: " << getDarkSecret() << '\n';
}
void Contact::search(int index)
{
	if (getFirstName() == "")
		return;
	std::cout << "|" << std::setw(10) << index << "|"
			<< std::setw(10) << draw_line(getFirstName()) << "|"
			<< std::setw(10) << draw_line(getLastName()) << "|"
			<< std::setw(10) << draw_line(getNickname()) << "|" << std::endl;
}