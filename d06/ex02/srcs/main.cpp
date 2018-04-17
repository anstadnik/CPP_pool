#include <header.h>

Base	*generate(void)
{
	Base	*ret;
	int		r = rand() % 3;

	std::cout << "Class: ";
	switch (r)
	{
		case 0:
			ret = new A;
			std::cout << "A" << std::endl;
			break ;
		case 1:
			ret = new B;
			std::cout << "B" << std::endl;
			break ;
		case 2:
			ret = new C;
			std::cout << "C" << std::endl;
			break ;
	}
	return (ret);
}

void	identify_from_pointer(Base *p)
{
	A	*heheyA = dynamic_cast<A*>(p);
	if (heheyA)
		std::cout << "A" << std::endl;
	B	*heheyB = dynamic_cast<B*>(p);
	if (heheyB)
		std::cout << "B" << std::endl;
	C	*heheyC = dynamic_cast<C*>(p);
	if (heheyC)
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base &p)
{
	bool	rez[3] = {true, true, true};
	try
	{
		Base	&trash = dynamic_cast<A &>(p);
		static_cast<void>(trash);
	}
	catch (std::bad_cast& e)
	{
		rez[0] = false;
	}
	try
	{
		Base	&trash = dynamic_cast<B &>(p);
		static_cast<void>(trash);
	}
	catch (std::bad_cast& e)
	{
		rez[1] = false;
	}
	try
	{
		Base	&trash = dynamic_cast<C &>(p);
		(void)trash;
	}
	catch (std::bad_cast& e)
	{
		rez[2] = false;
	}
	for (int i = 0; i < 3; i++)
		if (rez[i])
			std::cout << static_cast<char>('A' + i) << std::endl;
}

int	main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		Base	*anonymous = generate();
		identify_from_pointer(anonymous);
		identify_from_reference(*anonymous);
		delete anonymous;
	}
	return (0);
}
