#include "Phonebook.hpp"

void	Phonebook::add()
{
	std::cout << "Enter first_name: ";
	std::cin >> this->first_name;
	std::cout << "Enter last_name: ";
	std::cin >> this->last_name;
	std::cout << "Enter nickname: ";
	std::cin >> this->nickname;
	std::cout << "Enter postal_adress: ";
	std::cin >> this->postal_adress;
	std::cout << "Enter email_adress: ";
	std::cin >> this->email_adress;
	std::cout << "Enter phone_number: ";
	std::cin >> this->phone_number;
	std::cout << "Enter birthday_date: ";
	std::cin >> this->birthday_date;
	std::cout << "Enter favourite_meal: ";
	std::cin >> this->favourite_meal;
	std::cout << "Enter underwear_color: ";
	std::cin >> this->underwear_color;
	std::cout << "Enter darkest_secret: ";
	std::cin >> this->darkest_secret;
}

void	Phonebook::show_short(int num)
{
	std::cout << std::setw(10) << std::right;
	std::cout << num << " | ";

	std::cout << std::setw(10) << std::right;
	std::cout << (this->first_name.length() > 10 ?
			this->first_name.substr(0, 9).append(".") : this->first_name) << " | ";

	std::cout << std::setw(10) << std::right;
	std::cout << (this->last_name.length() > 10 ?
			this->last_name.substr(0, 9).append(".") : this->last_name) << " | ";

	std::cout << std::setw(10) << std::right;
	std::cout << (this->nickname.length() > 10 ?
			this->nickname.substr(0, 9).append(".") : this->nickname);

	std::cout << std::endl;
}

void	Phonebook::show()
{
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->postal_adress << std::endl;
	std::cout << this->email_adress << std::endl;
	std::cout << this->phone_number << std::endl;
	std::cout << this->birthday_date << std::endl;
	std::cout << this->favourite_meal << std::endl;
	std::cout << this->underwear_color << std::endl;
	std::cout << this->darkest_secret << std::endl;
}
