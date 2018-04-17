#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::string line;
		while (std::getline(std::cin, line))
			std::cout << line << std::endl;
	}
	else
		for (int i = 1; i < ac; i++)
		{
			std::ifstream	inp(av[i]);
			struct stat buf;
			stat(av[i], &buf);
			if (inp.fail())
				std::cout <<  "cat: " << av[i] << " No such file or directory" << std::endl;
			else if(!S_ISREG(buf.st_mode))
				std::cout << "cat: " << av[i] << " is a directory" << std::endl;
			else
			{
				inp.seekg(0, std::ios::beg);
				std::stringstream    file_buff;
				file_buff << inp.rdbuf();
				std::cout << file_buff.str() << std::endl;
			}
			inp.close();
		}
	return (1);
}
