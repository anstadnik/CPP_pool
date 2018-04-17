#include <iostream>
#include <stdlib.h>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	this->hp = 60;
	this->max_hp = 60;
	this->energy = 120;
	this->max_energy = 120;
	this->lvl = 1;
	this->name = "unnamed";
	this->melee = 60;
	this->ranged = 5;
	this->chicken = 35;
	this->magic = 25;
	this->sigfault = 50;
	this->armor = 0;
	std::cout << "Recompiling my combat code!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
{
	this->hp = 60;
	this->max_hp = 60;
	this->energy = 120;
	this->max_energy = 120;
	this->lvl = 1;
	this->name = name;
	this->melee = 60;
	this->ranged = 5;
	this->chicken = 35;
	this->magic = 25;
	this->sigfault = 50;
	this->armor = 0;
	std::cout << this->name << " is here to fight" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &src)
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

NinjaTrap::~NinjaTrap()
{
	std::cout << "This could've gone better!" << std::endl;
}


void	NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	std::cout << "This ninja trap is a " << trap.getName() << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	std::cout << "This frag trap is a " << trap.getName() << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	std::cout << "This scav trap is a " << trap.getName() << std::endl;
}

