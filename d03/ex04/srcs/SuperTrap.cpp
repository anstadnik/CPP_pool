#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap()
{
	this->hp = 100;
	this->max_hp = 100;
	this->energy = 120;
	this->max_energy = 120;
	this->lvl = 1;
	this->name = "unnamed";
	this->melee = 60;
	this->ranged = 20;
	this->chicken = 35;
	this->magic = 25;
	this->sigfault = 50;
	this->armor = 5;
	std::cout << "Recompiling my combat code!(as SuperTrap)" << std::endl;
}

SuperTrap::SuperTrap(std::string name)
{
	this->hp = 100;
	this->max_hp = 100;
	this->energy = 120;
	this->max_energy = 120;
	this->lvl = 1;
	this->name = name;
	this->melee = 60;
	this->ranged = 20;
	this->chicken = 35;
	this->magic = 25;
	this->sigfault = 50;
	this->armor = 5;
	std::cout << this->name << " is here to fight(as SuperTrap)" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &src)
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
	std::cout << "Copying my combat code!(as SuperTrap)" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "This could've gone better!(as SuperTrap)" << std::endl;
}
