#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>

class	FragTrap
{
	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		int	rangedAttack(std::string const & target);
		int	meleeAttack(std::string const & target);
		int	chickenAttack(std::string const & target);
		int	magicAttack(std::string const & target);
		int	sigfaultAttack(std::string const & target);
		int	takeDamage(unsigned int amount);
		int	beRepaired(unsigned int amount);
		int	vaulthunter_dot_exe(std::string const & target);
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
		unsigned int	chicken;
		unsigned int	magic;
		unsigned int	sigfault;
		unsigned int	armor;

};

#endif
