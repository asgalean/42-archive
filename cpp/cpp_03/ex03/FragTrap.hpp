#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	protected:
	
	static int defaultHP();
	static int defaultEP();
	static int defaultAD();

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
