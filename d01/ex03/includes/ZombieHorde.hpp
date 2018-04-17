#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP
#include "Zombie.hpp"

class	ZombieHorde
{
	public:

		ZombieHorde(int n);
		void	announce();
		~ZombieHorde();

	private:

		Zombie *army;
		int		num;
};

#endif
