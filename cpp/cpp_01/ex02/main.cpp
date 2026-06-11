#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "Memory adresses:" << std::endl << "Variable adress:\t" << &str << std::endl << "Pointer adress: \t" << stringPTR << std::endl << "Reference adress:\t" << &stringREF << std::endl;
	
	std::cout << "Values:" << std::endl << "Variable:\t" << str << std::endl << "Pointer:\t" << *stringPTR << std::endl << "Reference:\t" << stringREF << std::endl;
	
}
