#ifndef HUMAN_B
# define HUMAN_B

#include "Weapon.hpp"

class HumanB
{

	private:
		std::string name;
		Weapon *weapon_type;
		
	public:
		void attack();

		void setName(std::string new_name);
		void setWeapon(Weapon &new_weapon);
		
		Weapon getWeapon();
		std::string	getName();
		
		HumanB();
		HumanB(std::string new_name);
		~HumanB();
};

#endif
