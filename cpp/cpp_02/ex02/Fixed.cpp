#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int  Fixed::bits = 8;


int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}


Fixed::Fixed()
{
	this->value = 0;
}
Fixed::Fixed(const Fixed &num)
{
	this->value = num.value;  //becaues of the operator overwrite we can just do "*this = num"
}
Fixed& Fixed::operator= (const Fixed &num) // data type Fixed& and name operator=
{
	this->value = num.value;
	
	return (*this);
}

Fixed::~Fixed()
{

};


//************

Fixed::Fixed(const int num)
{
	this->value = num << 8; //like multiplying *256;
}
Fixed::Fixed(const float num)
{
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

//*************

bool Fixed::operator < (const Fixed &num) const
{
	return (this->value < num.value);
}
bool Fixed::operator > (const Fixed &num) const
{
	return (this->value > num.value);
}
bool Fixed::operator <= (const Fixed &num) const
{
	return (this->value <= num.value);
}
bool Fixed::operator >= (const Fixed &num) const
{
	return (this->value >= num.value);
}
bool Fixed::operator == (const Fixed &num) const
{
	return (this->value == num.value);
}
bool Fixed::operator != (const Fixed &num) const
{
	return (this->value != num.value);
}
Fixed Fixed::operator + (const Fixed &num) const
{
	Fixed result;
	result.setRawBits(this->value + num.value);	//doing >>8 and usign the constructor loses too
	return result;								//much precision for all 4 operators  
}									
Fixed Fixed::operator - (const Fixed &num) const
{
	Fixed result;
	result.setRawBits(this->value - num.value);
	return result;
}
Fixed Fixed::operator * (const Fixed &num) const
{
	Fixed result;
	result.setRawBits((this->value * num.value)>>8);
	return result;
}												  
Fixed Fixed::operator / (const Fixed &num) const
{
	Fixed result;
	result.setRawBits((this->value << 8) / num.value);
	return result;
}
//*************

Fixed& Fixed::operator++()
{
	(this->value)++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed prev(*this);
	
	(this->value)++;
	return (prev);
	
}
Fixed& Fixed::operator--()
{
(this->value)--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed prev(*this);
	
	(this->value)--;
	return (prev);
	
}
//**************

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1.value <= num2.value)
		return (num1);
	return (num2);
}
const Fixed& Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1.value <= num2.value)
		return (num1);
	return (num2);
}
Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1.value >= num2.value)
		return (num1);
	return (num2);
}
const Fixed& Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1.value >= num2.value)
		return (num1);
	return (num2);
}


