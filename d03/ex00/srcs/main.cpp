#include "FragTrap.hpp"
#include <stdlib.h>
#include <time.h>

int	main()
{
	srand(time(NULL));
	FragTrap army[4] = {FragTrap("Bronson"), FragTrap("Alpha"), FragTrap()};
	army[3] = FragTrap(army[2]);
	for (int i = 0; i < 20; i++)
		army[rand() % 4].vaulthunter_dot_exe(army[rand() % 4].getName());
	army[0].beRepaired(42);
	army[0].takeDamage(42);
	army[0].beRepaired(40);
	return (0);
}
