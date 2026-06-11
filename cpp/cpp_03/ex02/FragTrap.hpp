#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:
		
	void attack(const std::string& target);

	FragTrap();
	FragTrap(std::string noun);
	FragTrap(FragTrap& original);
	FragTrap& operator = (FragTrap& original);
	~FragTrap();


	void highFivesGuys();
};




#endif
