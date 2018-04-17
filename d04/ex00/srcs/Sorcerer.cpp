#include "Sorcerer.hpp"
#include <iostream>


Sorcerer::Sorcerer(void) {}

Sorcerer::Sorcerer(const Sorcerer &dst):name(dst.name), title(dst.title)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->name << ", " << this->title <<
		", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer	&Sorcerer::operator=(const Sorcerer &dst)
{
	this->name = dst.name;
	this->title = dst.title;
	return (*this);
}

std::string	Sorcerer::getName(void) const
{
	return (this->name);
}

std::string	Sorcerer::getTitle(void) const
{
	return (this->title);
}

std::ostream	&operator<<(std::ostream &os, const Sorcerer &dst)
{
	os << "I am " << dst.getName() << ", " << dst.getTitle() <<
		", and I like ponies !" << std::endl;
	return (os);
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}
