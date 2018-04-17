#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <time.h>
#include <stdlib.h>

int	main(void)
{
	srand(time(NULL));
	ZombieEvent	event;
	event.setZombieType("ordinary");
	Zombie		*zombie = event.newZombie("Potato");
	zombie->announce();
	event.setZombieType("archer");
	event.randomChump();
	delete(zombie);
	/* system("leaks zombie"); */
	return (0);
}
