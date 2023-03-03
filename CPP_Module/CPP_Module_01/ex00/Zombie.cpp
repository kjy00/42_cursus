#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) :_name(name) {}

Zombie::Zombie(void): _name("default") {}

Zombie::~Zombie() {
	std::cout << _name << " destroyed" << std::endl;
}
