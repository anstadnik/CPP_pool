#include "ScavTrap.hpp"
#include <iostream>
#include <stdlib.h>

ScavTrap::ScavTrap()
{
	std::cout << "Recompiling my combat code!(btw I'm a Scav)" << std::endl;
	this->hp = 100;
	this->max_hp = 100;
	this->energy = 50;
	this->max_energy = 50;
	this->lvl = 1;
	this->name = "unnamed";
	this->melee = 20;
	this->ranged = 15;
	this->armor = 3;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << this->name << " is here to fight(as a Scav of course)" << std::endl;
	this->hp = 100;
	this->max_hp = 100;
	this->energy = 100;
	this->max_energy = 100;
	this->lvl = 1;
	this->name = name;
	this->melee = 30;
	this->ranged = 20;
	this->armor = 5;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "Copying my combat code!(From a Scav, FYI)" << std::endl;
	this->hp = src.hp;
	this->max_hp = src.max_hp;
	this->energy = src.energy;
	this->max_energy = src.max_energy;
	this->lvl = src.lvl;
	this->name = src.name;
	this->melee = src.melee;
	this->ranged = src.ranged;
	this->armor = src.armor;
}

ScavTrap::~ScavTrap()
{
	std::cout << "This could've gone better!(Scav died. Because I am a Scav. I died... Ah, just forget)" << std::endl;
}

void	ScavTrap::challengeNewcomer(void)
{
	std::string sarr[4] = {"Give the one from the right of u a hug", "Do a backflip",
		"Tell ur intra password", "Do a lemin in 3 days"};
	std::cout << sarr[rand() % 4] << std::endl;
}
