#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public :
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNbr();
		std::string getSecret();
		void setFirstName(std::string);
		void setLastName(std::string);
		void setNickname(std::string);
		void setPhoneNbr(std::string);
		void setSecret(std:: string);
};

#endif
