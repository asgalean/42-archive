#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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


//************

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num << 8; //like multiplying *256;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * 256.0f);
}
		
int Fixed::toInt(void) const
{
	return (this->value >> 8); //like divinding /256
}
float Fixed::toFloat(void) const
{
	return (this->value /256.0f);
}
		
std::ostream& operator << (std::ostream& out, const Fixed& num)
{
	out << num.toFloat();
	return (out);
}


