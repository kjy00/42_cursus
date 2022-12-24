#include "./PhoneBook.hpp"

void printField(std::string str) {
	if (str.length() > 10) {
		str = str.substr(0, 10);
		str[9] = '.';
	}
	std::cout << std::setw(11) << str << "|";
}

void PhoneBook::setContactField(int n) {
	std::string tmp;

	while (1) {
		tmp.clear();
		std::getline(std::cin, tmp);
		if (std::cin.eof()) exit(0);
		if (!tmp.empty()) break;
		std::cout << "Invalid Input, try again." << std::endl;
	}
	if (n == 1)
		contact[idx].setFirstName(tmp);
	else if (n == 2)
		contact[idx].setLastName(tmp);
	else if (n == 3)
		contact[idx].setNickname(tmp);	
	else if (n == 4)
		contact[idx].setPhoneNbr(tmp);	
	else if (n == 5)
		contact[idx].setSecret(tmp);
}

void PhoneBook::add() {
	std::cout << "1. First name: ";
	PhoneBook::setContactField(1);
	std::cout << "2. Last name: ";
	PhoneBook::setContactField(2);
	std::cout << "3. Nickname: ";
	PhoneBook::setContactField(3);
	std::cout << "4. Phone Number: ";
	PhoneBook::setContactField(4);
	std::cout << "5. Darkest Secret: ";
	PhoneBook::setContactField(5);
	if (idx == 7)
		full = true;
	idx = (idx + 1) % 8;
}

int PhoneBook::printPhoneBook() {
	int	size;

	full ? size = 8 : size = idx;
	if (size == 0) {
		std::cout << "No Contacts in PhoneBook" << std::endl;
		return 1;
	}
	std::cout << "|";
	printField("Index"); printField("FirstName"); printField("LastName"); printField("Nickname");
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "|" << std::setw(11) << i + 1 << "|";
		printField(contact[i].getFirstName());
		printField(contact[i].getLastName());
		printField(contact[i].getNickname());
		std::cout << std::endl;
	}
	return 0;
}

void PhoneBook::search() {
	int	num;

	if (printPhoneBook()) return ;
	while (1) {
		std::cout << "Index(only 1 ~ 8): ";
		std::cin >> num;
		if (std::cin.eof()) exit(0);
		if (std::cin.fail() || num < 1 || num > 8 || (!full && num > idx)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Index!" << std::endl;
		}
		else break;
	}
	std::cin.ignore();
	std::cout << "1. First name: " << contact[num - 1].getFirstName() << std::endl
	<< "2. Last name: " << contact[num - 1].getLastName() << std::endl
	<< "3. Nickname: " << contact[num - 1].getNickname() << std::endl
	<< "4. Phone number: " << contact[num - 1].getPhoneNbr() << std::endl
	<< "5. Darkest secret: " << contact[num - 1].getSecret() << std::endl;
}

PhoneBook::PhoneBook(void): full(false), idx(0) {}
