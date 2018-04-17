#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include <iomanip>

class Phonebook
{
	public:

		void	add();
		void	show_short(int num);
		void	show();

	private:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	postal_adress;
		std::string	email_adress;
		std::string	phone_number;
		std::string	birthday_date;
		std::string	favourite_meal;
		std::string	underwear_color;
		std::string	darkest_secret;

};

#endif
