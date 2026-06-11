#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap Moe("Moe");
	FragTrap Lester("Lester");
	
	FragTrap Lester_v2(Lester);
	
	Lester_v2.highFivesGuys();
	for (int i=0;i < 110; i++)
	{
		Lester.attack("Moe");
		Moe.takeDamage(20);
		Moe.beRepaired(5);
		Lester_v2.beRepaired(20);
	}

}


/*
Main for ony ClapTrap

int main()
{
	ClapTrap a;
	ClapTrap b(a);
	ClapTrap Moe("Moe");
	ClapTrap Stachio("Stachio");

	for(int i = 0; i < 15; i++)
	{
		Moe.attack("Stachio");
		Stachio.takeDamage(1);
		Stachio.attack("air");
		a.beRepaired(1);
		b.beRepaired(1);
	}

}
*/
