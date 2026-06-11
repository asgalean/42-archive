#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//we added "virtual" in the other 2 classes, so they don't create more instances of ClapTrap
//because of that, in all the methods we have to call ClapTrap's constructors
class DiamondTrap : public ScavTrap, public FragTrap
{

	private:
		std::string name;
		
	
	public:
		void whoAmI();

		DiamondTrap();
		DiamondTrap(std::string noun);
		DiamondTrap(DiamondTrap& original);
		DiamondTrap& operator = (DiamondTrap& original);
		~DiamondTrap();
		
		//using ScavTrap::attack; so it only uses that one
		void attack(const std::string& target);
		
		void printStats();
};

#endif




