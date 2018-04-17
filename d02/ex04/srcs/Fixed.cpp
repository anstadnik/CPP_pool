#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

const int	Fixed::offs = 8;

std::ostream&	operator<<(std::ostream &os, const Fixed &fixed) 
{
	return (os << fixed.toFloat());
}

Fixed::Fixed():value(0)
{
	/* std::cout << "Default constructor called" << std::endl; */
}

Fixed::Fixed(int num)
{
	/* std::cout << "Int constructor called" << std::endl; */
	this->value = num << this->offs;
}

Fixed::Fixed(float num)
{
	/* std::cout << "Float constructor called" << std::endl; */
	/* this->value = (int)num << this->offs; */
	this->value = (int)roundf(num * (1 << this->offs));//-1
}

Fixed::Fixed(Fixed	const &dest):value(dest.value)
{
	/* std::cout << "Copy constructor called" << std::endl; */
	/* this->value = dest.getRawBits(); */
}

Fixed::~Fixed()
{
	/* std::cout << "Destructor called" << std::endl; */
}

Fixed&	Fixed::operator=(const Fixed &dst)
{
	/* std::cout << "Assignation operator called" << std::endl; */
	this->value = dst.value;
	return (*this);
}

float	Fixed::toFloat(void) const
{
	float	ret;

	ret = (float)this->value / (1 << this->offs);
	return (ret);
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->offs);
}

std::string	Fixed::toString(void) const
{
	std::stringstream st;
	st << std::setprecision(4) << std::fixed << this->toFloat();
	return (st.str());
}

int	Fixed::getRawBits(void) const
{
	/* std::cout << "getRawBits member function called" << std::endl; */
	return (this->value);
}

void Fixed::setRawBits(int const bits)
{
	/* std::cout << "setRawBits member function called" << std::endl; */
	this->value = bits;
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->value > fixed.value);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->value < fixed.value);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->value >= fixed.value);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->value <= fixed.value);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->value == fixed.value);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->value != fixed.value);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	Fixed	tmp;
	tmp.setRawBits(this->value + fixed.value);
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	Fixed	tmp;
	tmp.setRawBits(this->value - fixed.value);
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	Fixed	tmp;
	tmp.setRawBits((this->value * fixed.value) >> this->offs);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	if (!fixed.value)
		return (0);
	Fixed	tmp;
	tmp.setRawBits((this->value << this->offs) / fixed.value);
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	fixed(this->toFloat());
	this->value++;
	return (fixed);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed(this->toFloat());
	this->value--;
	return (fixed);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}
