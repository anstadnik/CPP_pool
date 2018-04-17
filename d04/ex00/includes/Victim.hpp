#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <string>

class	Victim
{
	public:

		Victim(const Victim &dst);
		Victim(const std::string &name);
		~Victim(void);
		Victim	&operator=(const Victim &dst);
		std::string	getName(void) const;
		virtual void getPolymorphed(void) const;

	protected:

		Victim(void);
		std::string	name;
};

std::ostream	&operator<<(std::ostream &os, const Victim &dst);

#endif
