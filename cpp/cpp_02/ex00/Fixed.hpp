#ifndef FIXED_HPP
# define FIXED_HPP



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
};




#endif
