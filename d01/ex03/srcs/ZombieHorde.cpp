#include "ZombieHorde.hpp"
#include <stdlib.h>

ZombieHorde::ZombieHorde(int n)
{
	this->army = new Zombie[n];
	this->num = n;
}

void	ZombieHorde::announce()
{
	for (int i = 0; i < this->num; i++)
		this->army[i].announce();
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->army;
}

