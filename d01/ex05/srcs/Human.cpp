#include "Human.hpp"
#include <string>

Human::Human(){}

std::string Human::identify()
{
	return (this->getBrain().identify());
}

const Brain	&Human::getBrain()
{
	return (this->brain);
}
