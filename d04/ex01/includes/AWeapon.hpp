#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <string>

class AWeapon
{
	private:

		AWeapon();

	protected:

		std::string name;
		int	damage;
		int	ap_cost;

	public:
		AWeapon(const AWeapon &dst);
		AWeapon	&operator=(const AWeapon &dst);
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();
		std::string getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
};

#endif
