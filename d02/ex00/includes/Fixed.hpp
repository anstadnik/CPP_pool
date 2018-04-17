#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed
{
	public:

		Fixed();
		Fixed(Fixed	const &dest);
		~Fixed();
		Fixed&	operator=(const Fixed &dst);
		int	getRawBits(void) const;
		void	setRawBits(int const bits);

	private:
		int	value;
		static const int	offs;

};

#endif
