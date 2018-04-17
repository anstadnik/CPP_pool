#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>

class	ScavTrap
{
	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		int	rangedAttack(std::string const & target);
		int	meleeAttack(std::string const & target);
		int	takeDamage(unsigned int amount);
		int	beRepaired(unsigned int amount);
		void	challengeNewcomer();
		std::string getName() const;

	private:

		unsigned int	hp;
		unsigned int	max_hp;
		unsigned int	energy;
		unsigned int	max_energy;
		unsigned int	lvl;
		std::string	name;
		unsigned int	melee;
		unsigned int	ranged;
		unsigned int	armor;

};

#endif
