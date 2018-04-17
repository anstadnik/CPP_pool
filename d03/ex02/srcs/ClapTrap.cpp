#include <ClapTrap.hpp>
#include <iostream>

ClapTrap::ClapTrap():hp(0), max_hp(0), energy(0), max_energy(0), lvl(0), name("unnamed"), melee(0), ranged(0), chicken(0), magic(0), sigfault(0), armor(0)
{
	std::cout << "Recompiling my combat code!(btw I'm a Clap)" << std::endl;
}

ClapTrap::ClapTrap(std::string name):hp(0), max_hp(0), energy(0), max_energy(0), lvl(0), name(name), melee(0), ranged(0), chicken(0), magic(0), sigfault(0), armor(0)
{
	std::cout << this->name << " is here to fight(as a Clap of course)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src):hp(src.hp), max_hp(src.max_hp), energy(src.energy), max_energy(src.max_energy), lvl(src.lvl), name(src.name), melee(src.melee), ranged(src.ranged), chicken(src.chicken), magic(src.magic), sigfault(src.sigfault), armor(src.armor)
{
	std::cout << "Copying my combat code!(From a Clap, FYI)" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "This could've gone better!(Clap died. Because I am a Clap. I died... Ah, just forget)" << std::endl;
}

unsigned int	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP-TP " << this->name << " attacks " << target << " at range, causing " << this->ranged << " points of damage !" << std::endl;
	return (this->ranged);
}

unsigned int	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP-TP " << this->name << " attacks " << target << " with melee, causing " << this->melee << " points of damage !" << std::endl;
	return (this->melee);
}

unsigned int	ClapTrap::chickenAttack(std::string const & target)
{
	std::cout << "FR4G-TP-TP " << this->name << " attacks " << target << " with chicken, causing " << this->chicken << " points of damage !" << std::endl;
	return (this->chicken);
}

unsigned int	ClapTrap::magicAttack(std::string const & target)
{
	std::cout << "FR4G-TP-TP " << this->name << " attacks " << target << " with magic, causing " << this->magic << " points of damage !" << std::endl;
	return (this->magic);
}

unsigned int	ClapTrap::sigfaultAttack(std::string const & target)
{
	std::cout << "FR4G-TP-TP " << this->name << " attacks " << target << " with sigfault, causing " << this->sigfault << " points of damage !" << std::endl;
	return (this->sigfault);
}

unsigned int	ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)(this->hp - amount + this->armor) < 0)
		std::cout << "FR4G-TP-TP " << this->name << " is dead already, leave him alone!" << std::endl;
	else
	{
		std::cout << "FR4G-TP-TP " << this->name << " took " << amount - armor << " of damage." << std::endl;
		this->hp -= amount + this->armor;
	}
	return (this->hp);
}

unsigned int	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp + amount > this->max_hp)
	{
		this->hp = this->max_hp;
		std::cout << "FR4G-TP-TP " << this->name << " doesn't need ur help" << std::endl;
	}
	else
	{
		this->hp += amount;
		std::cout << "FR4G-TP-TP " << this->name << " was repaired by " << amount << " hp" << std::endl;
	}
	return (this->hp);
}

std::string ClapTrap::getName() const
{
	return (this->name);
}
