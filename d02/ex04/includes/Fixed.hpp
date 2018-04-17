#ifndef FIXED_HPP
#define FIXED_HPP
#include <sstream>

class	Fixed
{
	public:

		Fixed();
		Fixed(int num);
		Fixed(float num);
		Fixed(Fixed	const &dest);
		~Fixed();
		Fixed	&operator=(const Fixed &dst);
		float	toFloat(void) const;
		int	toInt(void) const;
		std::string toString(void) const;
		int	getRawBits(void) const;
		void	setRawBits(int const bits);
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static Fixed	&min(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);

	private:
		int	value;
		static const int	offs;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
