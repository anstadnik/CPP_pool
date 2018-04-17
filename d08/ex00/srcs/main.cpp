#include "easyfind.hpp"
#include <vector>
#include <list>
#include <exception>
#include <iostream>

int	main()
{
	int	arr[] = {1, 2, 3, 5};
	std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(int));
	std::list<int>		l(arr, arr + sizeof(arr) / sizeof(int));
	try
	{
		std::vector<int>::const_iterator	rez = easyfind(v, 2);
		std::cout << "Found " << *rez << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::list<int>::const_iterator	rez = easyfind(l, 2);
		std::cout << "Found " << *rez << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::list<int>::const_iterator	rez = easyfind(l, 4);
		std::cout << "Found " << *rez << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
