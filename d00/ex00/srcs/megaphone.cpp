#include <iostream>
#include <stdio.h>

static void	convert(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 'a' - 'A';
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < ac; i++)
		{
			convert(av[i]);
			std::cout << av[i];
		}
	std::cout << std::endl;
	return (0);
}
