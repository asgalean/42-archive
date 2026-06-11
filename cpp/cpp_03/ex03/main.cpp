#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap Pisstachio("Pisstachio");
	
	Pisstachio.whoAmI();
	Pisstachio.printStats();
	for (int i = 0;i < 10;i++)
	{
		Pisstachio.attack("self");
		Pisstachio.takeDamage(30);
	}
}


/*
Main for ony ClapTrap

int main()
{
	ClapTrap a;
	ClapTrap b(a);
	ClapTrap Piss("Piss");
	ClapTrap Stachio("Stachio");

	for(int i = 0; i < 15; i++)
	{
		Piss.attack("Stachio");
		Stachio.takeDamage(1);
		Stachio.attack("air");
		a.beRepaired(1);
		b.beRepaired(1);
	}

}
*/
