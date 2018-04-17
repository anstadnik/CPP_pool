#include <FragTrap.hpp>
#include <ScavTrap.hpp>
#include <stdlib.h>
#include <time.h>

int	main()
{
	srand(time(NULL));
	FragTrap army[4] = {FragTrap("Bronson"), FragTrap("Alpha"), FragTrap()};
	ScavTrap army2[4] = {ScavTrap("Bronson"), ScavTrap("Alpha"), ScavTrap()};
	army[3] = FragTrap(army[2]);
	army2[3] = ScavTrap(army2[2]);
	for (int i = 0; i < 20; i++)
		army[rand() % 4].vaulthunter_dot_exe(army[rand() % 4].getName());
	for (int i = 0; i < 20; i++)
		army2[rand() % 4].challengeNewcomer();
	army[0].beRepaired(42);
	army[0].takeDamage(42);
	army[0].beRepaired(40);
	return (0);
}
