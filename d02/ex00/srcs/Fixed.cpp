#include "Fixed.hpp"
#include <iostream>

const int	Fixed::offs = 8;

Fixed::Fixed():value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed	const &dest)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = dest.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &dst)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = dst.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const bits)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = bits;
}

