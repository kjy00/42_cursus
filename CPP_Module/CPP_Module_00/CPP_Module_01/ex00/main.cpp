#include "Zombie.hpp"
#include <iostream>

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main(void) {
	Zombie defaultZ;
	defaultZ.announce();

	randomChump("stackZombie");

	Zombie *newZ;
	newZ = newZombie("heapZombie");
	newZ->announce();
	delete newZ;
	return (0);
}
