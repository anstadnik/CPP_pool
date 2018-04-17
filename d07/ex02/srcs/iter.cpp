#include "Array.hpp"
#include <random>
#include <time.h>
#include <limits>
#include <iostream>

int	main(void)
{
	std::srand(time(NULL));
	Array<int>	iarr(5);
	Array<double>	darr(5u);
	Array<std::string>	sarr(5u);
	try
	{
		for (int i = 0; i < 6; i++)
			iarr[i] = std::rand() % std::numeric_limits<int>::max();
	}
	catch (std::out_of_range e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Output" << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
	{
		darr[i] = std::rand();
		for (int j = 0; j < 10; j++)
			sarr[i].push_back(rand() % (std::numeric_limits<char>::max() - 34) + 34);
	}
	std::cout << "int len:" << iarr.size() <<std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << iarr[i] << std::endl;
	std::cout << std::endl;
	std::cout << "double len:" << darr.size() <<std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << darr[i] << std::endl;
	std::cout << std::endl;
	std::cout << "string len:" << sarr.size() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << sarr[i] << std::endl;
	return (0);
}
