#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *z = zombieHorde(3, "zombie");
	for (int i = 0; i < 3 ; i++)
		z[i].announce();
	delete [] z;
	return (0);
}
