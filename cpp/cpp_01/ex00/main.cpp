#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );


#include <cstdlib>
int main()
{
	Zombie *alfred;
	
	alfred = newZombie("Alfred");
	randomChump("Carl");
	
	(*alfred).announce();
	delete alfred;
	
	std::cout << "I'm gonna be called before the destructor" << std::endl;
}




