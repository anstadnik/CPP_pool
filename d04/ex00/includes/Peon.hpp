#ifndef PEON_HPP
#define PEON_HPP
#include "Victim.hpp"

class	Peon: public Victim
{
	public:

		Peon(const Peon &dst);
		Peon(const std::string &name);
		~Peon(void);
		Peon	&operator=(const Peon &dst);
		void getPolymorphed(void) const;

	private:

		Peon(void);

};

#endif
