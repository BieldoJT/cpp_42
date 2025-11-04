#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed(void)
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Fixed Int Constructor called" << std::endl;
	this->_value = value << this->_frac_bits;
}


Fixed::Fixed(const float value)
{
	std::cout << "Fixed Float Constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_frac_bits));
}



Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}


float Fixed::toFloat( void ) const
{
	return (float)_value / (1 << _frac_bits);
}

int Fixed::toInt( void ) const
{
	return _value >> _frac_bits;
}

std::ostream& operator <<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}
