#include "Phonebooks.hpp"

Phonebooks::Phonebooks():counter(0) {}

void	Phonebooks::add()
{
	if (this->counter < 7)
		this->arr[this->counter++].add();
	else
		std::cout << "Maximum amount of contacts reached" << std::endl;
}

void	Phonebooks::search()
{
	std::cout << std::setw(13) << std::right;
	std::cout << "index | ";

	std::cout << std::setw(13) << std::right;
	std::cout << "first name | ";

	std::cout << std::setw(13) << std::right;
	std::cout << "last name | ";

	std::cout << std::setw(10) << std::right;
	std::cout << "nickname";

	std::cout << std::endl;
	for (int i = 0; i < this->counter; i++)
		arr[i].show_short(i);
	int	num;
	std::cout << "Enter number of contact: ";
	std::cin >> num;
	if (num >= 0 && num < this->counter)
		arr[num].show();
	else
		std::cout << "Wrong number" << std::endl;
}
