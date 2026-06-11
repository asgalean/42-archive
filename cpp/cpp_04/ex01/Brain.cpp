#include "Brain.hpp"


Brain::Brain()
{
	static int idea_number = 0;
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << idea_number;
		ideas[i] = "Idea number " + ss.str();
		idea_number++;
	}
	std::cout << "Brain default constutrcotr called" << std::endl;
}

Brain::Brain(Brain& other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constutrcotr called" << std::endl;
}


Brain& Brain::operator = (Brain& other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignment copy opertor called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
