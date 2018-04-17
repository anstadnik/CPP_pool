#ifndef SPAN_HPP
#define SPAN_HPP
#include <stdlib.h>
#include <exception>

class	Span
{
	public:

		Span();
		Span(const Span &orig);
		Span(const int	amount);
		Span	&operator=(const Span &orig);
		~Span();

		void	addNumbers(int *first, int *last);
		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);

		class	FullSpan: public std::exception
	{
		public:
			char const	*what(void) const throw();
	};
	private:

		int		*end;
		int		*beg;
		size_t	len;
		size_t	used;

};

#endif
