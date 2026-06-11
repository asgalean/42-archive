#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{

	Zombie *array = new  Zombie[N];
	
	for (int i = 0; i < N; i++)
		array[i].set_name(name);
	
	return (array);
}
