#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream> 
#include <stdint.h>
#include <cstdlib>

class Contact
{
	
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string darkest_secret;
	
	public:
		Contact();
		Contact(std::string f_name, std::string l_name, std::string n_name, std::string nbr, std::string d_s);
		Contact(const Contact& o_contact); //Copy constructor since c++98 doesnt have move constructors
		//same but with assignment copy operator (&& instead of & to make it a move operator)
		Contact& operator=(const Contact& o_contact);
		Contact operator+(Contact& o_contact);
		~Contact();
		void Print();
		
		std::string getFname();
		std::string getLname();
		std::string getNname();
		std::string getNumber();
		std::string getDsecret();
};

#endif
