#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->brain = new Brain(*(other.brain));
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain; //to free the memory, cuz we about to copy the other brain, boiiiiii
		this->brain = new Brain(*(other.brain));
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
	delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

std::string Cat::getIdea(int index)
{
	if (index >= 0 && index < 100)
		return (this->brain->ideas[index]);
	return ("Echoing void");
}
