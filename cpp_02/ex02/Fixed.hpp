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

		bool operator>(Fixed const other) const;
		bool operator<(Fixed const other) const;
		bool operator>=(Fixed const other) const;
		bool operator<=(Fixed const other) const;
		bool operator==(Fixed const other) const;
		bool operator!=(Fixed const other) const;
		float operator+(Fixed const other) const;
		float operator-(Fixed const other) const;
		float operator*(Fixed const other) const;
		float operator/(Fixed const other) const;

		Fixed operator++(int); // i++
		Fixed operator++(); // ++i
		Fixed operator--(int); // i--
		Fixed operator--(); //--i





		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		//if i use inside classe, i must use friend

		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);


};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
