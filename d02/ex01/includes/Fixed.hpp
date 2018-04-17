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
		Fixed&	operator=(const Fixed &dst);
		float	toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void) const;
		void	setRawBits(int const bits);

	private:
		int	value;
		static const int	offs;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
