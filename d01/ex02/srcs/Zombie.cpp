#include "Zombie.hpp"
# include <iostream>

void	Zombie::announce(void)
{
	std::cout << this->name << " " << this->type << " Aaaaaappplleeeee"
		<< std::endl;
}

Zombie::Zombie()
{
	this->name = "";
	this->type = "type";
	this->name.append(1, rand() % 26 + 'A');
	for (int i = 0; i < 9; i++)
	{
		this->name.append(1, rand() % 26 + 'a');
	}

}

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie died(again)" << std::endl;
}
