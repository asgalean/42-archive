#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int HP;
		int EP;
		int AD;
	
	protected:
		void setName(std::string noun);
		void setHP(int hp);
		void setEP(int ep);
		void setAD(int ad);
		
		std::string getName() const; //rember, const because it oesn't modify the variable
		int getHP() const;
		int getEP() const;
		int getAD() const;
		
		
	
	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		ClapTrap();
		ClapTrap(std::string noun);
		ClapTrap(ClapTrap& original);
		ClapTrap& operator = (ClapTrap& original);
		~ClapTrap();


};

#endif
