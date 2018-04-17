#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <ClapTrap.hpp>
#include <string>

class	ScavTrap: public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		void	challengeNewcomer();
};

#endif
