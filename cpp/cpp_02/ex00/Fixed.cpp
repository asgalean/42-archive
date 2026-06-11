#include "Fixed.hpp"
#include <iostream>

const int  Fixed::bits = 8;


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	
	this->value = raw;
}


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}
Fixed::Fixed(const Fixed &num)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = num.value;  //becaues of the operator overwrite we can just do "*this = num"
}
Fixed& Fixed::operator= (const Fixed &num) // data type Fixed& and name operator=
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	this->value = num.value;
	
	return (*this);
}

Fixed::~Fixed()
{
		std::cout << "Destructor called" << std::endl;
};
