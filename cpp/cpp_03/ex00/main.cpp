#include "ClapTrap.hpp"

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

// Even though CLpatrap has 0 damage, the test makes Stachio lose 1 life per hit
// to check all possible cases
