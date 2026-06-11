#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string temp;
	system("clear");
	std::cout << "Welcome to your phonebook! Commands: ADD, SEARCH, EXIT" << std::endl;
	while (std::getline(std::cin, temp))
	{
		if (temp == "ADD")
			phonebook.Add();
		if (temp == "SEARCH")
			phonebook.Search();
		if (temp == "EXIT")
			break ;
			//phonebook.Exit();
		system("clear");
		std::cout << "Welcome to your phonebook! Commands: ADD, SEARCH, EXIT" << std::endl;
	}
};
