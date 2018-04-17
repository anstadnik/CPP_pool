#include <Victim.hpp>
#include <iostream>

Victim::Victim(void) {}

Victim::Victim(const Victim &dst)
{
	this->name = dst.name;
	std::cout << "Some random victim called " << this->name <<
	   " just popped !" << std::endl;
}

Victim::Victim(const std::string &name)
{
	this->name = name;
	std::cout << "Some random victim called " << this->name <<
	   " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->name <<
	   " just died for no apparent reason !" << std::endl;
}

Victim	&Victim::operator=(const Victim &dst)
{
	this->name = dst.name;
	return (*this);
}

void Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep !" <<
		std::endl;
}

std::string	Victim::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &os, const Victim &dst)
{
	os << "I'm " << dst.getName() << " and I like otters !" << std::endl;
	return (os);
}

