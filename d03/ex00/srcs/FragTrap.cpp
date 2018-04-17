#include "FragTrap.hpp"
#include <iostream>
#include <stdlib.h>



FragTrap::FragTrap():hp(100), max_hp(100), energy(100), max_energy(100), lvl(1), name("unnamed"), melee(30), ranged(20), chicken(35), magic(25), sigfault(50), armor(5)
{
	std::cout << "Recompiling my combat code!" << std::endl;
}

FragTrap::FragTrap(std::string name):hp(100), max_hp(100), energy(100), max_energy(100), lvl(1), name(name), melee(30), ranged(20), chicken(35), magic(25), sigfault(50), armor(5)
{
	std::cout << this->name << " is here to fight" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src):hp(src.hp), max_hp(src.max_hp), energy(src.energy), max_energy(src.max_energy), lvl(src.lvl), name(src.name), melee(src.melee), ranged(src.ranged), chicken(src.chicken), magic(src.magic), sigfault(src.sigfault), armor(src.armor)
{
	std::cout << "Copying my combat code!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "This could've gone better!" << std::endl;
}

int	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " at range, causing " << this->ranged << " points of damage !" << std::endl;
	return (this->ranged);
}

int	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " with melee, causing " << this->melee << " points of damage !" << std::endl;
	return (this->melee);
}

int	FragTrap::chickenAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " with chicken, causing " << this->chicken << " points of damage !" << std::endl;
	return (this->chicken);
}

int	FragTrap::magicAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " with magic, causing " << this->magic << " points of damage !" << std::endl;
	return (this->magic);
}

int	FragTrap::sigfaultAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " with sigfault, causing " << this->sigfault << " points of damage !" << std::endl;
	return (this->sigfault);
}

int	FragTrap::takeDamage(unsigned int amount)
{
	if ((int)(this->hp - amount + this->armor) < 0)
		std::cout << "FR4G-TP " << this->name << " is dead already, leave him alone!" << std::endl;
	else
	{
		std::cout << "FR4G-TP " << this->name << " took " << amount - armor << " of damage." << std::endl;
		this->hp -= amount + this->armor;
	}
	return (this->hp);
}

int	FragTrap::beRepaired(unsigned int amount)
{
	if (this->hp + amount > this->max_hp)
	{
		this->hp = this->max_hp;
		std::cout << "FR4G-TP " << this->name << " doesn't need ur help" << std::endl;
	}
	else
	{
		this->hp += amount;
		std::cout << "FR4G-TP " << this->name << " was repaired by " << amount << " hp" << std::endl;
	}
	return (this->hp);
}

int	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int	(FragTrap::*arr[5])(std::string const & target) =
	{&FragTrap::rangedAttack, &FragTrap::meleeAttack, &FragTrap::chickenAttack,
		&FragTrap::magicAttack, &FragTrap::sigfaultAttack};
	if (this->energy > 25)
	{
		this->energy -= 25;
		return ((this->*arr[rand() % 5])(target));
	}
	std::cout << "Not enoung energy" << std::endl;
	return (0);
}

std::string FragTrap::getName() const
{
	return (this->name);
}
