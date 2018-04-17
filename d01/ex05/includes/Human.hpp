#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"
# include <string>

class	Human
{
	public:

		Human();
		std::string		identify();
		const Brain		&getBrain();

	private:

		Brain const	brain;

};

#endif
