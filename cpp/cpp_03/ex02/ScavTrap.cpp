#include "ScavTrap.hpp"

//note to future self
//setName ==> calls own, if not, calls inherited
//ClapTrap::setName ==> calls parent method explicitltyu
//ScavTrap::setName ==> calls own maethod explicitclty

ScavTrap::ScavTrap() : ClapTrap()
{
	//instead of having  this->HP = smth, and have those variables protected
	//we use getters, because if we have to change those variables, it's eaasier and 
	//we'd only have to change the setter, and not the childs. Also, more control this way
	std::cout << "*BIP BIP* DEFAULT SCAVTRAP CREATED" << std::endl;
	//getName() = "anon"; no need, it inherits ClapTrap's
	setHP(100); //parent setter
	setEP(50);
	setAD(20);
}


//calling the ClapTRap constructor first adn then modify it
// 1. ClapTrap(noun) runs:
//	- Sets name = noun
//	- Sets HP = 10
//	- Sets EP = 10
//	- Sets AD = 0
//	and then our code
ScavTrap::ScavTrap(const std::string noun) : ClapTrap(noun) 
{
	std::cout << "*BIP BIP* ARGUMENT SCAVTRAP CREATED" << std::endl;
	//setName(noun);
	setHP(100);
	setEP(50);
	setAD(20);
}


ScavTrap::ScavTrap(ScavTrap& original) : ClapTrap(original)
{
	std::cout << "*BIP BIP* COPY SCAVTRAP CREATED" << std::endl;
	//no need to write anything since ClapTrap copy constructor already copies everything
	//if ScavTrap had any attributes that CalpTrap desn't, thne we'd need to writre them here
}


ScavTrap& ScavTrap::operator = (ScavTrap& original)
{
	//because it's a method and not a constructor we can't call it like the construcotrs (outide)
	ClapTrap::operator=(original);
	std::cout << "*BIP BIP* COPY ASSIGN SCAVTRAP CREATED" << std::endl;
	
	return (*this);
}

ScavTrap::~ScavTrap() 
{
	std::cout << "*BIP BIP* SCAVTRAP DESTRUCTOR CALLED" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (getHP() <= 0)
		std::cout << getName() << " has no Hit Points left and can't do any action" << std::endl;
	else if (getEP() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAD() << " points of damage!" << std::endl;
		setEP(getEP()-1);
	}
	else
		std::cout << getName() << " doesn't have enough Energy Points for this action" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}
