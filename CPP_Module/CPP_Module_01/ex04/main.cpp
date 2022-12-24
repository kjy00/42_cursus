#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "[Usage]: ./SedIsForLosers <file_name> <s1> <s2>" << std::endl;
		return 0; 
	}

	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (s1.empty()) {
		std::cout << "String1 must NOT be empty." << std::endl;
		return 0;
	}

	std::ifstream ifs_src(argv[1]);
	if (ifs_src.fail()) {
		std::cout << "No such file" << std::endl;
		return 0;
	}

	std::ofstream ofs_dst((std::string(argv[1]) + ".replace").c_str());
	if (ofs_dst.fail()) {
		std::cout << "Open file failed." << std::endl;
		return (0);
	}

	std::string line;
	while(std::getline(ifs_src, line, '\0')) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ofs_dst << line;
	}
	ifs_src.close();
	ofs_dst.close();
	return 0;
}
