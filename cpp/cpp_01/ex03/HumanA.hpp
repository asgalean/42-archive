#ifndef HUMAN_A
# define HUMAN_A

#include "Weapon.hpp"

class HumanA
{

	private:
		std::string name;
		Weapon &weapon_type;
		
	public:
		void attack();

		void setName(std::string new_name);
		void setWeapon(Weapon &new_weapon);
		
		Weapon getWeapon();
		std::string	getName();
		
		HumanA();
		HumanA(std::string new_name, Weapon &new_weapon);
		~HumanA();
};

#endif
