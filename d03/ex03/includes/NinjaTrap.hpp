#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	NinjaTrap: public ClapTrap
{
	public:

		NinjaTrap();
		NinjaTrap(std::string name);
		NinjaTrap(const NinjaTrap &src);
		~NinjaTrap();
		void	ninjaShoebox(NinjaTrap &trap);
		void	ninjaShoebox(FragTrap &trap);
		void	ninjaShoebox(ScavTrap &trap);

};

#endif
