#include "PlasmaRifle.hpp"
#include <iostream>


PlasmaRifle::PlasmaRifle():AWeapon("PlasmaRifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &dst):AWeapon(dst) {}

PlasmaRifle	&PlasmaRifle::operator=(const PlasmaRifle &dst)
{
	this->name = dst.getName();
	this->damage = dst.getDamage();
	this->ap_cost = dst.getAPCost();
	return (*this);
}

PlasmaRifle::~PlasmaRifle() {}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
