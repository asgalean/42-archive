#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "utf8_handling.hpp"

class PhoneBook
{
	private:
		Contact phonebook[8];
		int	saved_contacts;
	
	public:
		PhoneBook();
		
		
		//falta sobreescribir el operador []
		Contact& operator[](int i);
		
		int getSavedContacts();
		
		void Add();
		void Search(); //Buscar por posicion
		void Exit(); //cuiadod ctrl+D


};

#endif
