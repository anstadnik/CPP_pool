#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap()
{
	std::cout << "Making a pony on Heap" << std::endl;
	Pony *pony = new Pony();
	pony->speak();
	delete(pony);
}

void	ponyOnTheStack()
{
	std::cout << "Making a pony on Stack" << std::endl;
	Pony pony;
	pony.speak();
}

int	main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (1);
}
