#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap Piss("Piss");
	ScavTrap Tachio("Tachio");
	
	ScavTrap Tachio_v2(Tachio);
	
	Tachio_v2.guardGate();
	for (int i=0;i < 60; i++)
	{
		Tachio.attack("Piss");
		Piss.takeDamage(20);
		Piss.beRepaired(5);
		Tachio_v2.beRepaired(20);
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
