#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "1";
	this->last_name = "1";
	this->nickname = "1";
	this->number = "1";
	this->darkest_secret = "1";
};

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string nbr, std::string d_s)
{
	this->first_name = f_name;
	this->last_name = l_name;
	this->nickname = n_name;
	this->number = nbr;
	this->darkest_secret = d_s;
};




Contact::Contact(const Contact& o_contact)
{
	this->first_name = o_contact.first_name;
	this->last_name = o_contact.last_name;
	this->nickname = o_contact.nickname;
	this->number = o_contact.number;
	this->darkest_secret = o_contact.darkest_secret;
	/*
	o_contact.first_name= "";
	o_contact.last_name= "";
	o_contact.nickname= "";
	o_contact.number= "";
	o_contact.darkest_secret= "";
	*/
};

Contact Contact::operator+(Contact& o_contact)
{
	std::cout << "Concatenation operator called" << std::endl;
	Contact temp;
	
	temp.first_name = first_name + o_contact.first_name;
	temp.last_name = last_name + o_contact.last_name;
	temp.nickname = nickname + o_contact.nickname;
	temp.number = number + o_contact.number;
	temp.darkest_secret = darkest_secret + o_contact.darkest_secret;
	
	return temp;
};


Contact& Contact::operator=(const Contact& o_contact) //assign operator
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &o_contact)
	{
		this->first_name = o_contact.first_name;
		this->last_name = o_contact.last_name;
		this->nickname = o_contact.nickname;
		this->number = o_contact.number;
		this->darkest_secret = o_contact.darkest_secret;
		
		/*
		o_contact.first_name= "";
		o_contact.last_name= "";
		o_contact.nickname= "";
		o_contact.number= "";
		o_contact.darkest_secret= "";
		*/
	}

	return *this;
};

Contact::~Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->number = "";
	this->darkest_secret = "";
}

void Contact::Print()
{
	std::cout << "First name:\t" << this->first_name << std::endl; 
	std::cout << "Last name:\t" << this->last_name << std::endl;
	std::cout << "Nickname:\t" << this->nickname << std::endl;
	std::cout << "Number:\t\t" << this->number << std::endl;
	std::cout << "Darkest secret:\t" << this->darkest_secret << std::endl;
};

//Getters
std::string Contact::getFname()
{
	return (this->first_name);
};

std::string Contact::getLname()
{
	return (this->last_name);
};

std::string Contact::getNname()
{
	return (this->nickname);
};

std::string Contact::getNumber()
{
	return (this->number);
};

std::string Contact::getDsecret()
{
	return (this->darkest_secret);
};
