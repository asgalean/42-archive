#include "HumanB.hpp"

void HumanB::attack()
{

	std::cout << this->name << " attacks with their " ;
	
	if (this->weapon_type != NULL)
		std::cout << this->weapon_type->getType() << std::endl; 
	else
		std::cout << "fists" << std::endl;
}

void HumanB::setName(std::string new_name)
{
	this->name = new_name;
}


void HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon_type = &new_weapon;
}

Weapon HumanB::getWeapon()
{
	if (this->weapon_type != NULL)
		return (*(this->weapon_type));
	return (Weapon());
}


std::string	HumanB::getName()
{
	return (this->name);
}


HumanB::HumanB(std::string new_name)
{
	this->name = new_name;
	this->weapon_type = NULL;
}


HumanB::~HumanB()
{

}
