#include "Logger.hpp"

int main()
{
	Logger l1("potato");
	Logger l2("not potato");
	l1.log("Console", "hehey");
	l1.log("File", "hehey");
	l1.log("potato", "hehey");
	l2.log("Console", "hehey");
	l2.log("File", "hehey");
	l2.log("potato", "hehey");
	return (0);
}
