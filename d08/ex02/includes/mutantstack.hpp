#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template<typename T>
class	MutantStack: public std::stack<T>
{
	public:

		/* typedef typename std::stack<T>::iterator iterator; */
		/* typedef typename std::stack<T>::const_iterator const_iterator; */
		// exposing iterators of the underlying container
		MutantStack(void) {};
		MutantStack(const MutantStack &orig):std::stack<T>(orig) {};
		MutantStack	&operator=(const MutantStack &orig)
		{
			return (std::stack<T>::operator=(orig));
		};
		~MutantStack(void) {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typename std::stack<T>::container_type::iterator    begin() { return std::stack<T>::c.begin(); }
		typename std::stack<T>::container_type::iterator    end() { return std::stack<T>::c.end(); }
};

#endif
