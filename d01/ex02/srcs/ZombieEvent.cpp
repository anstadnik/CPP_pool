#include "ZombieEvent.hpp"
# include <iostream>
#include <stdlib.h>

ZombieEvent::ZombieEvent()
{
	this->type = "type";
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->type));
}

void	ZombieEvent::randomChump()
{
	std::string str= "";

	str.append(1, rand() % 26 + 'A');
	for (int i = 0; i < 9; i++)
		str.append(1, rand() % 26 + 'a');
	Zombie	zombie(str, this->type);
	zombie.announce();
}
