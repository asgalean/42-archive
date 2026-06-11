#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
	
	static int defaultHP();
	static int defaultEP();
	static int defaultAD();

	public:
		
	void attack(const std::string& target);

	ScavTrap();
	ScavTrap(std::string noun);
	ScavTrap(ScavTrap& original);
	ScavTrap& operator = (ScavTrap& original);
	~ScavTrap();


	void guardGate();
};




#endif
