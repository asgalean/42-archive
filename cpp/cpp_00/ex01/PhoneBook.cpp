#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	//for (int i = 0; i < 8; i++)
		//this->phonebook[i] = Contact(); //en principio ya se hace cuando se declara el array estatico
	this->saved_contacts = 0;
};



Contact create_contact()
{
	std::string	f_n;
	std::string	l_n;
	std::string	n_n;
	std::string	nbr;
	std::string d_s;


	std::cout << "First name:" << std::endl;
	std::getline(std::cin, f_n);
	std::cout << "Last name:" << std::endl;
	std::getline(std::cin, l_n);
	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin, n_n);
	std::cout << "Number:" << std::endl;
	std::getline(std::cin, nbr);
	std::cout << "Darkest secret:" << std::endl;
	std::getline(std::cin, d_s);
	
	Contact temp(f_n, l_n, n_n, nbr, d_s);
	
	std::string holder;
	std::cout << "Contact added." << std::endl << "Going back to main menu. Enter anything to continue." << std::endl;
	std::getline(std::cin, holder);
	return (temp);
};


Contact& PhoneBook::operator[](int i)
{
	if (i >= saved_contacts || i < 0)
	{
		std::cout << "Accesing out of bounds index, terminating program" << std::endl;
		std::exit (0);
	}
	return (phonebook[i]);
};

int PhoneBook::getSavedContacts()
{
	return (this->saved_contacts);
};

void PhoneBook::Add()
{
	static int	position = 0;
	if (position > 7)
		position = 0;
	this->phonebook[position] = create_contact(); //puedo hacer un constructor de move para esto? SI
	position++;
	if (this->saved_contacts < 8)
		this->saved_contacts++;
};

void PhoneBook::Search()
{
	int i = 0;
	int space_len = 0;
	system("clear");
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "__________|__________|__________|__________|" << std::endl;
	while (i < saved_contacts)
	{
		std::string display;
		space_len = 9; //Index printing
		while (space_len > 0)
		{
			std::cout << " ";
			space_len--;
		}
		std::cout << i << "|";
		
		//FIRST name printnig
		display = truncate_with_ellipsis(this->phonebook[i].getFname(), 10);
		space_len = 10 - utf8_display_width(display);
		while (space_len > 0) 
		{
			std::cout << " ";
			space_len--;
		}
		std::cout << truncate_with_ellipsis(this->phonebook[i].getFname(), 10) << "|";
	
		//LAST name printnig
		display = truncate_with_ellipsis(this->phonebook[i].getLname(), 10);
		space_len = 10 - utf8_display_width(display);
		while (space_len > 0) 
		{
			std::cout << " ";
			space_len--;
		}
		std::cout << truncate_with_ellipsis(this->phonebook[i].getLname(), 10) << "|";
		
		//NICKNAME printnig
		display = truncate_with_ellipsis(this->phonebook[i].getNname(), 10);
		space_len = 10 - utf8_display_width(display);
		while (space_len > 0) 
		{
			std::cout << " ";
			space_len--;
		}
		std::cout << truncate_with_ellipsis(this->phonebook[i].getNname(), 10) << "|";
		
		
		
		std::cout << std::endl;
		std::cout << "__________|__________|__________|__________|" << std::endl;

		i++;
	}
	
	std::string temp;
	std::cout << std::endl << "Please enter the index of contact you want to see or RETURN to go back." << std::endl << "Entering anything other tan a valid index will go back to the main menu." << std::endl;
	std::getline(std::cin, temp);
	
	if (temp != "RETURN")
	{
		if ((temp[0] >= '0' && temp[0] < '9') && (temp[0] - '0') < this->getSavedContacts())
			this->phonebook[temp[0] - '0'].Print();
		
		std::cout << "Going back to main menu. Enter anything to continue." << std::endl;
		std::getline(std::cin, temp);
	}
};

void PhoneBook::Exit()
{
	//std::exit(0);
};

