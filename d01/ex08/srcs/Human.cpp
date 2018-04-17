#include "Human.hpp"
#include <iostream>

void Human::meleeAttack(std::string const & target)
{
	std::cout << "Attacking " << target << " with melee" << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "Attacking " << target << " with bow" << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Attacking " << target << " with my face(terrible)" << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	std::string	sarr[3] = {"melee", "bow", "ugliness"};
	void (Human::*farr[3])(std::string const & target) = 
	{&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	for (int i = 0; i < 3; i++)
		if (sarr[i] == action_name)
		{
			(this->*farr[i])(target);
			return ;
		}
	std::cout << "Wrong action, " << target << " is alive" << std::endl;
}

