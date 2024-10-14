#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		Contact contacts[8];
		void search()
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
};

#endif