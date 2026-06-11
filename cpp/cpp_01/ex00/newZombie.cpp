#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *jack = new Zombie(name);
	
	return (jack);
}
