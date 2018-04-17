#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"
#include <string>

class	ZombieEvent
{
	public:

		ZombieEvent();
		void	setZombieType(std::string type);
		void	randomChump();
		Zombie	*newZombie(std::string name);

	private:

		std::string	type;

};

#endif
