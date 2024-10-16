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
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNum();
		std::string getDarkSecret();
		void setFirstName(std::string str);
		void setLastName(std::string str);
		void setNickname(std::string str);
		void setPhoneNum(std::string str);
		void setDarkSecret(std::string str);
		int add();
		std::string draw_line(std::string str);
		void display();
		void search(int index);
};

#endif