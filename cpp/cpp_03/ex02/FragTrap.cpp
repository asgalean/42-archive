#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "*BIP BIP* DEFAULT FRAGTRAP CREATED" << std::endl;
	setHP(100); 
	setEP(100);
	setAD(30);
}


FragTrap::FragTrap(const std::string noun) : ClapTrap(noun) 
{
	std::cout << "*BIP BIP* ARGUMENT FRAGTRAP CREATED" << std::endl;
	setHP(100);
	setEP(100);
	setAD(30);
}


FragTrap::FragTrap(FragTrap& original) : ClapTrap(original)
{
	std::cout << "*BIP BIP* COPY FRAGTRAP CREATED" << std::endl;
}


FragTrap& FragTrap::operator = (FragTrap& original)
{
	ClapTrap::operator=(original);
	std::cout << "*BIP BIP* COPY ASSIGN FRAGTRAP CREATED" << std::endl;
	
	return (*this);
}

FragTrap::~FragTrap() 
{
	std::cout << "*BIP BIP* FRAGTRAP DESTRUCTOR CALLED" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (getHP() <= 0)
		std::cout << getName() << " has no Hit Points left and can't do any action" << std::endl;
	else if (getEP() > 0)
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << " causing " << getAD() << " points of damage!" << std::endl;
		setEP(getEP()-1);
	}
	else
		std::cout << getName() << " doesn't have enough Energy Points for this action" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Hey, it's me, " << getName() << " the FragTrap! Give me a high five!" << std::endl;
}
