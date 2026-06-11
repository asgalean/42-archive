#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
	private:
	
		std::string name;
		
		
	public:
	
		std::string get_name();
		void announce();
		
		Zombie();
		Zombie(std::string z_name);
		~Zombie();


};

#endif
