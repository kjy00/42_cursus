#include "./PhoneBook.hpp"

int main(void)
{
	std::string input;
	PhoneBook p;
	while (true)
	{
		std::cout << "<Input SEARCH / ADD / EXIT>" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return 0;
		if (!input.compare("ADD"))
			p.add();
		else if (!input.compare("SEARCH"))
			p.search();
		else if (!input.compare("EXIT"))
			return 0;
		else
			std::cout << "Invalid Input" << std::endl;
	}
	return 0;
}
