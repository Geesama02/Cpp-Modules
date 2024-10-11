#ifndef CONATCT_HPP
# define CONATCT_HPP

#include <iostream>

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
		Contact() { std::cout << "Contact Created!\n"; }
		void setFirstName(std::string str) { firstName = str; }
		void setLastName(std::string str) { lastName = str; }
		void setNickname(std::string str) { nickname = str; }
		void setPhoneNum(std::string str) { phoneNum = str; }
		void setDarkSecret(std::string str) { darkSecret = str; }
};

#endif