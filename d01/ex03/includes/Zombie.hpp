#ifndef ZOMBIE
# define ZOMBIE
#include <string>

class	Zombie
{
	public:

		Zombie();
		Zombie(std::string, std::string type);
		~Zombie();
		void	announce(void);

	private:

		std::string name;
		std::string type;
};

#endif
