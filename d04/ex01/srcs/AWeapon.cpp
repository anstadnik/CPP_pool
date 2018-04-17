#include "AWeapon.hpp"


AWeapon::AWeapon() {}

AWeapon::AWeapon(const AWeapon &dst):name(dst.name), damage(dst.damage), ap_cost(dst.ap_cost)
{
}

AWeapon	&AWeapon::operator=(const AWeapon &dst)
{
	this->name = dst.getName();
	this->damage = dst.getDamage();
	this->ap_cost = dst.getAPCost();
	return (*this);
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->name = name;
	this->damage = damage;
	this->ap_cost = apcost;
}

AWeapon::~AWeapon() {}

std::string AWeapon::getName() const
{
	return (this->name);
}

int AWeapon::getAPCost() const
{
	return (this->ap_cost);
}

int AWeapon::getDamage() const
{
	return (this->damage);
}
