#include "Zombie.hpp"

std::string Zombie::get_name()
{
	return (this->name);
}

void Zombie::announce()
{
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string z_name)
{
	this->name = z_name;
}

Zombie::~Zombie()
{
	std::cout << get_name() << " died" << std::endl;
}
