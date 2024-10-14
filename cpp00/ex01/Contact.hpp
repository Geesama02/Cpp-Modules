#ifndef CONATCT_HPP
# define CONATCT_HPP

#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNum;
		std::string darkSecret;
	public:
		std::string getFirstName() { return (firstName); }
		std::string getLastName() { return (lastName); }
		std::string getNickname() { return (nickname); }
		std::string getPhoneNum() { return (phoneNum); }
		std::string getDarkSecret() { return (darkSecret); }
		void setFirstName(std::string str) { firstName = str; }
		void setLastName(std::string str) { lastName = str; }
		void setNickname(std::string str) { nickname = str; }
		void setPhoneNum(std::string str) { phoneNum = str; }
		void setDarkSecret(std::string str) { darkSecret = str; }
		void add()
		{
			std::string tmp;
			std::cout << "Enter First Name: ";
			std::cin >> tmp;
			setFirstName(tmp);
			std::cout << "Enter Last Name: ";
			std::cin >> tmp;
			setLastName(tmp);
			std::cout << "Enter Nickname: ";
			std::cin >> tmp;
			setNickname(tmp);
			std::cout << "Enter Phone Number: ";
			std::cin >> tmp;
			setPhoneNum(tmp);
			std::cout << "Enter Darkest Secret: ";
			std::cin >> tmp;
			setDarkSecret(tmp);
		}

		std::string draw_line(std::string str)
		{
			if (str.length() > 10)
				return (str.substr(0, 9) + '.');
			return (str);
		}
		void display()
		{
			std::cout << "First Name: " << getFirstName() << '\n';
			std::cout << "Last Name: " << getLastName() << '\n';
			std::cout << "Nickname: " << getNickname() << '\n';
			std::cout << "Phone Number: " << getPhoneNum() << '\n';
			std::cout << "Darkest Secret: " << getDarkSecret() << '\n';
		}

		void search(int index)
		{
			std::cout << "|" << std::setw(10) << index << "|"
					<< std::setw(10) << draw_line(getFirstName()) << "|"
					<< std::setw(10) << draw_line(getLastName()) << "|"
					<< std::setw(10) << draw_line(getNickname()) << "|" << std::endl;
		}
};

#endif