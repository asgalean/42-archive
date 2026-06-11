#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("anon_clap_name"), ScavTrap(), FragTrap()
{
    std::cout << "*BIP BIP* DEFAULT DIAMONDTRAP CREATED" << std::endl;
	this->name = "anon";
	setHP(FragTrap::defaultHP());
	setEP(ScavTrap::defaultEP());
	setAD(FragTrap::defaultAD());
}

DiamondTrap::DiamondTrap(std::string noun) : ClapTrap(noun + "_clap_name"), ScavTrap(), FragTrap()
{//no need to pass noun ot other consturtcotsrs
    std::cout << "*BIP BIP* ARGUMENT DIAMONDTRAP CREATED" << std::endl;
	this->name = noun;
	setHP(FragTrap::defaultHP());
	setEP(ScavTrap::defaultEP());
	setAD(FragTrap::defaultAD());
}

DiamondTrap::DiamondTrap(DiamondTrap& original) : ClapTrap(original), ScavTrap(original), FragTrap(original)
{//we need to pass original to other constructos in order to not lose information
    std::cout << "*BIP BIP* COPY DIAMONDTRAP CREATED" << std::endl;
	this->name = original.name;
}

DiamondTrap& DiamondTrap::operator = (DiamondTrap& original)
{
	ClapTrap::operator=(original);
    ScavTrap::operator=(original);
    FragTrap::operator=(original);
    this->name = original.name;
    
    std::cout << "*BIP BIP* DIAMONDTRAP ASSIGNMENT" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "*BIP BIP* DIAMONDTRAP DESTRUCTOR" << std::endl;
}



void DiamondTrap::whoAmI()
{
	std::cout << "Am I " << this->name << " (DiamondTrap name) or " << ClapTrap::getName() << " (ClapTrap name)?" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::printStats()
{
	std::cout << "HP: " << getHP() << std::endl;
    std::cout << "EP: " << getEP() << std::endl;
    std::cout << "AD: " << getAD() << std::endl;
}
