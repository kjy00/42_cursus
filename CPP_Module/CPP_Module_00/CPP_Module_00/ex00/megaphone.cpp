#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (argv++; *argv; argv++) {
		std::string s;
		s = *argv;
		for (int i = 0 ; i < (int)s.size(); i++)
			std::cout << (char)std::toupper(s[i]);
	}
	std::cout << std::endl;
	return 0;
}
