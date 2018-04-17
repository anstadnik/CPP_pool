#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class	FragTrap: public ClapTrap
{
	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		int	vaulthunter_dot_exe(std::string const & target);
};

#endif
