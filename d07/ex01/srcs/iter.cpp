#include <iostream>
#include <random>
#include <time.h>
#include <limits>

template<typename T>
void	iter(T *p, size_t s, void (*f)(const T &))
{
	for (size_t i = 0; i < s; i++)
		f(p[i]);
}

void	ip(const int &n)
{
	std::cout << "int " << n << std::endl;
}

void	cp(const char &n)
{
	std::cout << "char " << n << std::endl;
}

template<typename T>
void	Tp(const T &n)
{
	std::cout << "T " << n << std::endl;
}

int	main(void)
{
	srand(time(NULL));
	int		iarr[15];
	char	carr[15];
	double	darr[15];
	std::string	sarr[15];

	for (int i = 0; i < 15; i++)
	{
		iarr[i] = rand() % std::numeric_limits<int>::max();
		carr[i] = rand() % (std::numeric_limits<char>::max() - 34) + 34;
		darr[i] = rand();
		for (int j = 0; j < 10; j++)
			sarr[i].push_back(rand() % (std::numeric_limits<char>::max() - 34) + 34);
	}
	iter(iarr, 15, &ip);
	std::cout << std::endl;
	iter(carr, 15, &cp);
	std::cout << std::endl;
	iter(darr, 15, &Tp);
	std::cout << std::endl;
	iter(sarr, 15, &Tp);
	std::cout << std::endl;
	return (0);
}
