#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if (this->HP <= 0)
		std::cout << this->name << "has no Hit Points left and can't do any action" << std::endl;
	else if (this->EP > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing 1 points of damage!" << std::endl;
		this->EP--;
	}
	else
		std::cout << this->name << " doesn't have enough Energy Points for this action" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HP <= 0)
	{
		std::cout << "Stop! " << this->name << " is aready dead!" << std::endl;
		return ;
	}
	this->HP -= amount;
	if (this->HP <= 0)
		std::cout << this->name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HP <= 0)
		std::cout << this->name << " has no Hit Points left and can't do any action" << std::endl;
	else if (this->EP > 0)
	{
		this->HP += amount;
		std::cout << this->name << " got healed " << amount << "points" << std::endl;
		this->EP--;
	}
	else
		std::cout << this->name <<" doesn't have enough Energy Points for this action" << std::endl;
}

ClapTrap::ClapTrap()
{
	std::cout << "*BIP BIP* DEFAULT CLAPTRAP CREATED" << std::endl;
	this->name = "anon";
	this->HP = 10;
	this->EP = 10;
	this->AD = 0;
}


ClapTrap::ClapTrap(const std::string noun)
{
	std::cout << "*BIP BIP* ARGUMENT CLAPTRAP CREATED" << std::endl;
	this->name = noun;
	this->HP = 10;
	this->EP = 10;
	this->AD = 0;
}


ClapTrap::ClapTrap(ClapTrap& original)
{
	std::cout << "*BIP BIP* COPY CLAPTRAP CREATED" << std::endl;
	this->name = original.name;
	this->HP = original.HP;
	this->EP = original.EP;
	this->AD = original.AD;
}


ClapTrap& ClapTrap::operator = (ClapTrap& original)
{
	std::cout << "*BIP BIP* COPY ASSIGN CLAPTRAP CREATED" << std::endl;
	this->name = original.name;
	this->HP = original.HP;
	this->EP = original.EP;
	this->AD = original.AD;
	
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "*BIP BIP* CLAPTRAP DESTRUCTOR CALLED" << std::endl;
}



void ClapTrap::setName(std::string noun)
{
	this->name = noun;
}
void ClapTrap::setHP(int hp)
{
	this->HP = hp;
}
void ClapTrap::setEP(int ep)
{
	this->EP = ep;
}
void ClapTrap::setAD(int ad)
{
	this->AD = ad;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}
int ClapTrap::getHP() const
{
	return (this->HP);
}
int ClapTrap::getEP() const
{
	return (this->EP);
}
int ClapTrap::getAD() const
{
	return (this->AD);
}

