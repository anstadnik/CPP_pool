#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <numeric>

Span::Span():end(NULL), beg(NULL), len(0), used(0) {} 

Span::Span(const Span &orig):len(orig.len), used(orig.used)
{
	beg = new int[len]();
	end = std::copy(orig.beg, orig.end, beg);
} 

Span::Span(const int len):len(len)
{
	beg = new int[len]();
	used = 0;
	end = beg;
} 

Span	&Span::operator=(const Span &orig)
{
	len = orig.len;
	end = orig.end;
	beg = new int[len]();
	std::copy(orig.beg, orig.end, beg);
	return (*this);
}

Span::~Span(void)
{
	if (beg)
		delete [] beg;
}

char const	*Span::FullSpan::what(void) const throw()
{
	return ("Span is full");
}

void	Span::addNumber(int n)
{
	if (used == len)
		throw FullSpan();
	*end++ = n;
	used++;
}

void	Span::addNumbers(int *first, int *last)
{
	if (last < first)
		throw FullSpan();
	if (static_cast<unsigned int>(last - first) / sizeof(int) > len - used)
		throw (std::range_error("Last is bigger than first"));
	end = std::copy(first, last, end);
	used += static_cast<unsigned int>(last - first);
}

int		Span::shortestSpan(void)
{
	std::vector<int>	differences(len);
	std::sort(beg, end);
	std::adjacent_difference(beg, end, differences.begin());
	return (*std::min_element(differences.begin(), differences.end()));
}

int		Span::longestSpan(void)
{
	//check for NULL
	std::sort(beg, end);
	return (end[-1] - *beg);
}
