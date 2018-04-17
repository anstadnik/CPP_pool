#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class	ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();
		unsigned int	rangedAttack(std::string const & target);
		unsigned int	meleeAttack(std::string const & target);
		unsigned int	chickenAttack(std::string const & target);
		unsigned int	magicAttack(std::string const & target);
		unsigned int	sigfaultAttack(std::string const & target);
		unsigned int	takeDamage(unsigned int amount);
		unsigned int	beRepaired(unsigned int amount);
		std::string getName() const;

	protected:

		unsigned int	hp;
		unsigned int	max_hp;
		unsigned int	energy;
		unsigned int	max_energy;
		unsigned int	lvl;
		std::string		name;
		unsigned int	melee;
		unsigned int	ranged;
		unsigned int	chicken;
		unsigned int	magic;
		unsigned int	sigfault;
		unsigned int	armor;
};

#endif
