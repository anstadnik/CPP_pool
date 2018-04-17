#include "ex01.h"

int	main(void)
{
	std::string	input;
	Phonebooks	instance;

	do
	{
		std::cout << "Input something: ";
		std::cin >> input;
		if (input == "ADD")
			instance.add();
		else if (input == "SEARCH")
			instance.search();
		else if (input == "EXIT")
			std::cout << "Bye-bye" << std::endl;
		else
			std::cout << "Wrong input" << std::endl;
	} while (input != "EXIT");
	return (0);
}
