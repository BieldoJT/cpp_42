#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>



class Fixed
{
	private:
		int _value;
		static const int _frac_bits;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed(Fixed const &copy);
		Fixed &operator=(Fixed const &other);


		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		//if i use inside classe, i must use friend


};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
