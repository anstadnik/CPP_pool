#include "FragTrap.hpp"
#include <iostream>
#include <stdlib.h>

FragTrap::FragTrap()
{
	this->hp = 100;
	this->max_hp = 100;
	this->energy = 100;
	this->max_energy = 100;
	this->lvl = 1;
	this->name = "unnamed";
	this->melee = 30;
	this->ranged = 20;
	this->chicken = 35;
	this->magic = 25;
	this->sigfault = 50;
	this->armor = 5;
	std::cout << "Recompiling my combat code!" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->hp = 100;
	this->max_hp = 100;
	this->energy = 100;
	this->max_energy = 100;
	this->lvl = 1;
	this->name = name;
	this->melee = 30;
	this->ranged = 20;
	this->chicken = 35;
	this->magic = 25;
	this->sigfault = 50;
	this->armor = 5;
	std::cout << this->name << " is here to fight" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
{
	this->hp = src.hp;
	this->max_hp = src.max_hp;
	this->energy = src.energy;
	this->max_energy = src.max_energy;
	this->lvl = src.lvl;
	this->name = src.name;
	this->melee = src.melee;
	this->ranged = src.ranged;
	this->chicken = src.chicken;
	this->magic = src.magic;
	this->sigfault = src.sigfault;
	this->armor = src.armor;
	std::cout << "Copying my combat code!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "This could've gone better!" << std::endl;
}

int	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	unsigned int	(ClapTrap::*arr[5])(std::string const & target) =
	{&ClapTrap::rangedAttack, &ClapTrap::meleeAttack, &ClapTrap::chickenAttack,
		&ClapTrap::magicAttack, &ClapTrap::sigfaultAttack};
	if (this->energy > 25)
	{
		this->energy -= 25;
		return ((this->*arr[rand() % 5])(target));
	}
	std::cout << "Not enoung energy" << std::endl;
	return (0);
}
