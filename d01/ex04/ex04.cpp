#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*p = &str;
	std::string	&r = str;
	std::cout << "str : " << str << std::endl;
	std::cout << "pointer : " << *p << std::endl;
	std::cout << "reference : " << r << std::endl;
	return (0);
}
