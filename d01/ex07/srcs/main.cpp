#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/stat.h>

static int	err()
{
	std::cout << "Error" << std::endl;
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 4 || !std::string(av[2]).length() || !std::string(av[3]).length())
		return (err());
	std::ifstream	i(av[1]);
	struct stat buf;
	stat(av[1], &buf);
	if (i.fail() || !S_ISREG(buf.st_mode))
		return (err());
	std::ofstream	o(std::string(av[1]).append(".replace"));
	if (o.fail())
		return (err());
	std::stringstream    file_buff;
	file_buff << i.rdbuf();
	std::string str = file_buff.str();
	for (size_t	index = 0; index != std::string::npos; index = str.find(av[2], index))
	{
		str.replace(index, std::string(av[2]).length(), av[3]);
		index += std::string(av[2]).length();
	}
	o << str;
	o.close();
	i.close();
	return (0);
}
