#include "Zombie.hpp"
#include <iostream>

class Zombie;

Zombie::Zombie(std::string name) :_name(name) {}

Zombie::Zombie(void): _name("default") {}

Zombie::~Zombie() {
	std::cout << _name << " destroyed" << std::endl;
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { _name = name; }
