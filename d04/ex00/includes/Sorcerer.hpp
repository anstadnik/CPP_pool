#ifndef SORCERER_HPP
#define SORCERER_HPP
#include <string>
#include "Victim.hpp"

class	Sorcerer
{
	public:

		Sorcerer(const Sorcerer &dst);
		Sorcerer(const std::string &name, const std::string &title);
		~Sorcerer(void);
		Sorcerer	&operator=(const Sorcerer &dst);
		std::string	getName(void) const;
		std::string	getTitle(void) const;
		void polymorph(Victim const &victim) const;

	private:

		Sorcerer(void);
		std::string	name;
		std::string	title;
};

std::ostream	&operator<<(std::ostream &os, const Sorcerer &dst);

#endif
