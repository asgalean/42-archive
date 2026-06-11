#include "Weapon.hpp"

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

const std::string  &Weapon::getType()
{
	return (this->type);
}

Weapon::Weapon()
{
	this->type = "fist";
}

Weapon::Weapon(std::string new_weapon)
{
	this->type = new_weapon;
}

Weapon::~Weapon()
{
	
}
