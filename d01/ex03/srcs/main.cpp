#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <time.h>
#include <stdlib.h>

int	main(void)
{
	srand(time(NULL));
	ZombieHorde	horde(20);
	horde.announce();
	return (0);
}
