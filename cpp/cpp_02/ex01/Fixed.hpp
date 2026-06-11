#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

// tradduccion, los ultimos 8 BITS del int "value", son los que almacenan los decimales
// osea, es como hacerle /256 al int para conseguir el numero

class Fixed
{

	private:
	
		int value;
		static const int  bits;



	public:
		
		int getRawBits(void) const; //creo que esto indica que no va a modificar nada
		void setRawBits(int const raw);
		
		Fixed();
		Fixed(const Fixed &num);
		Fixed& operator = (const Fixed &num);
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		
		int toInt(void) const;
		float toFloat(void) const;
		
};

std::ostream& operator<< (std::ostream& out, const Fixed& num);



#endif
