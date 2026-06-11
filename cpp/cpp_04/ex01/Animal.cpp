#include "Animal.hpp"

Animal::Animal()// : type("")
{
	this->type = "";
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)// : type(other.type)
{
	this->type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal() //we dnot put "vitrual" here
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Is it a bird? Is it a plane?" << std::endl;
}

std::string Animal::getIdea(int index)
{
    (void)index;  // Unused, just because the children functoins need an index
    return "Animals don't have complex thoughts";
}
