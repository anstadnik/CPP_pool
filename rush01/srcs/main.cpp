#include "Monitor.hpp"
#include <iostream>
#include <exception>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	try
	{
		Monitor	monitor(av[1]);
		monitor.run();
	}
	catch (std::invalid_argument e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
};
