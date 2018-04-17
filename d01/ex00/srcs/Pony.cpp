#include "Pony.hpp"
# include <iostream>

Pony::Pony()
{
	std::cout << "Such an incredible Pony was born" << std::endl << std::endl;
}

Pony::~Pony()
{
	std::cout << "This Pony went to paradice" << std::endl << std::endl;
}

void	Pony::speak()
{
	std::cout << "Look at my horn" << std::endl << "My horn is amazing" <<
		std::endl << std::endl;
}
