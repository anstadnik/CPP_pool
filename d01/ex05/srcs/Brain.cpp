#include "Brain.hpp"
#include <sstream>

std::string Brain::identify() const
{
	std::ostringstream address;

	address << this;
	return (address.str());
}
