#include "header.h"

void	*serialize(void)
{
	Data	*data = new Data;
	for (int i = 0; i < 8; i++)
		data->s1.push_back((rand() % 93 + 33));
	data->n = rand() % INT_MAX;
	for (int i = 0; i < 8; i++)
		data->s2.push_back(rand() % 93 + 33);
	return (reinterpret_cast<void *>(data));
}

Data	*deserialize(void *raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	std::srand(time(NULL));
	Data	*rez = deserialize(serialize());
	std::cout << rez->s1 << std::endl;
	std::cout << rez->n << std::endl;
	std::cout << rez->s2 << std::endl;
	delete rez;
	return (0);
}
