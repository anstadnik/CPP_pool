#include "ScavTrap.hpp"
#include <iostream>
#include <stdlib.h>



ScavTrap::ScavTrap():hp(100), max_hp(100), energy(50), max_energy(50), lvl(1), name("unnamed"), melee(20), ranged(15), armor(3)
{
	std::cout << "Recompiling my combat code!" << std::endl;
}

ScavTrap::ScavTrap(std::string name):hp(100), max_hp(100), energy(100), max_energy(100), lvl(1), name(name), melee(30), ranged(20), armor(5)
{
	std::cout << this->name << " is here to fight" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src):hp(src.hp), max_hp(src.max_hp), energy(src.energy), max_energy(src.max_energy), lvl(src.lvl), name(src.name), melee(src.melee), ranged(src.ranged), armor(src.armor)
{
	std::cout << "Copying my combat code!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "This could've gone better!" << std::endl;
}

int	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC@V-TP " << this->name << " attacks " << target << " at range, causing " << this->ranged << " points of damage !" << std::endl;
	return (this->ranged);
}

int	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC@V-TP " << this->name << " attacks " << target << " with melee, causing " << this->melee << " points of damage !" << std::endl;
	return (this->melee);
}

int	ScavTrap::takeDamage(unsigned int amount)
{
	if ((int)(this->hp - amount + this->armor) < 0)
		std::cout << "SC@V-TP " << this->name << " is dead already, leave him alone!" << std::endl;
	else
	{
		std::cout << "SC@V-TP " << this->name << " took " << amount - armor << " of damage." << std::endl;
		this->hp -= amount + this->armor;
	}
	return (this->hp);
}

int	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hp + amount > this->max_hp)
	{
		this->hp = this->max_hp;
		std::cout << "SC@V-TP " << this->name << " doesn't need ur help" << std::endl;
	}
	else
	{
		this->hp += amount;
		std::cout << "SC@V-TP " << this->name << " was repaired by " << amount << " hp" << std::endl;
	}
	return (this->hp);
}

void	ScavTrap::challengeNewcomer(void)
{
	std::string sarr[4] = {"Give the one from the right of u a hug", "Do a backflip",
		"Tell ur intra password", "Do a lemin in 3 days"};
	std::cout << sarr[rand() % 4] << std::endl;
}

std::string ScavTrap::getName() const
{
	return (this->name);
}
