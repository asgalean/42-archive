#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );


int main()
{
	Zombie *horde;
	
	horde = zombieHorde(5, "Carl");
	
	for (int i = 0; i<5; i++)
		horde[i].announce();

	delete[] horde;
	
	std::cout << "Finished program" << std::endl;
}
