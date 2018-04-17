#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP
#include "AWeapon.hpp"

class	PlasmaRifle: public AWeapon
{
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &dst);
		PlasmaRifle	&operator=(const PlasmaRifle &dst);
		~PlasmaRifle();
		void attack() const;
};

#endif
