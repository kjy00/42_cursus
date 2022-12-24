#include "HumanB.hpp"
#include <iostream>

void HumanB::attack() {
	std::cout << _name << "  attacks with their " 
	<< (_weapon ? _weapon->getType() : "fist") << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

HumanB::HumanB(std::string name):_name(name), _weapon(NULL) {}
