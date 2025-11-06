#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed(void)
{
	_value = 0;
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_frac_bits;
}


Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_frac_bits));
}



Fixed &Fixed::operator=(Fixed const &other)
{
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(Fixed const other) const
{
	if(this->toFloat() > other.toFloat())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const other) const
{
	if(this->toFloat() < other.toFloat())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const other) const
{
	if(this->toFloat() >= other.toFloat())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const other) const
{
	if(this->toFloat() <= other.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const other) const
{
	if(this->toFloat() == other.toFloat())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const other) const
{
	if(this->toFloat() != other.toFloat())
		return true;
	return false;
}

float Fixed::operator+(Fixed const other) const
{
	return (this->toFloat() + other.toFloat());
}

float Fixed::operator-(Fixed const other) const
{

	return (this->toFloat() - other.toFloat());
}

float Fixed::operator*(Fixed const other) const
{
	return (this->toFloat() * other.toFloat());
}

float Fixed::operator/(Fixed const other) const
{
	return (this->toFloat() / other.toFloat());
}

//post increment / decremente
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_value;
	return (tmp);
}
//pre increment / decrement

Fixed Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return a;
	else
		return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() <= b.toFloat())
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{

	if (a.toFloat() >= b.toFloat())
		return a;
	else
		return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() >= b.toFloat())
		return a;
	else
		return b;
}

int Fixed::getRawBits(void) const
{
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
