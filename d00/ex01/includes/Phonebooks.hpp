#ifndef PHONEBOOKS_HPP
# define PHONEBOOKS_HPP
# include "Phonebook.hpp"
# include <string>
# include <iostream>
# include <iomanip>

class	Phonebooks
{
	public:

		Phonebooks();
		void	add();
		void	search();

	private:

		int			counter;
		Phonebook	arr[8];
};

#endif
