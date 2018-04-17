#include "Peon.hpp"
#include <iostream>

Peon::Peon(void) {}

Peon::Peon(const Peon &dst):Victim::Victim(dst)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const std::string &name):Victim::Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon	&Peon::operator=(const Peon &dst)
{
	this->name = dst.name;
	return (*this);
}

void Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony !" <<
		std::endl;
}
