#include "HumanA.hpp"



void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon_type.getType() << std::endl; 

}

void HumanA::setName(std::string new_name)
{
	this->name = new_name;
}


void HumanA::setWeapon(Weapon &new_weapon)
{
	this->weapon_type = new_weapon;
}

Weapon HumanA::getWeapon()
{
	return (this->weapon_type);
}


std::string	HumanA::getName()
{
	return (this->name);
}


HumanA::HumanA(std::string new_name, Weapon &new_weapon) : weapon_type(new_weapon)
{
	this->name = new_name;
}


HumanA::~HumanA()
{

}
