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
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input!\n";
			break;
		}
		if (cmd == "ADD")
		{
			if (my_phonebook.contacts[index].add())
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
				{
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					indexToView = 0;
				}
				if (indexToView <= 8 && indexToView >= 1)
					my_phonebook.contacts[indexToView - 1].display();
				else
					std::cout << "Invalid Index!\n";
			}
		}
	}
	return (0);
}
