#include "Fixed.hpp"
#include <iostream>

std::string eval_expr(std::string expr)
{
	size_t beg;
	size_t end;
	beg = expr.find("(");
	end = expr.find_last_of(")");
	if (beg != std::string::npos && end != std::string::npos)
	{
		if (beg == std::string::npos || end == std::string::npos)
			throw(2);
		expr.replace(beg, end - beg + 1, eval_expr(expr.substr(beg + 1, end - 2)));
	}
	while ((beg = expr.find_first_of("*/")) != std::string::npos)
	{
		char oper = expr[beg];
		size_t lbeg = expr.find_last_of("!*/+-", beg - 1) + 1;
		size_t lend = expr.find_first_of("$*/+-", beg + 1) - 1;
		if (lend == beg || lbeg == beg)
			throw(3);
		Fixed n1(std::stof(expr.substr(lbeg, beg - lbeg)));
		Fixed n2(std::stof(expr.substr(beg + 1, lbeg - beg)));
		if (oper == '*')
			expr.replace(lbeg, lend - lbeg + 1, (n1 * n2).toString());
		else
			expr.replace(lbeg, lend - lbeg + 1, (n1 / n2).toString());
	}
	while ((beg = expr.find_first_of("+-")) != std::string::npos)
	{
		char oper = expr[beg];
		size_t lbeg = expr.find_last_of("!*/+-", beg - 1) + 1;
		size_t lend = expr.find_first_of("$*/+-", beg + 1) - 1;
		if (lend == beg || lbeg == beg)
			throw(3);
		Fixed n1(std::stof(expr.substr(lbeg, beg - lbeg)));
		Fixed n2(std::stof(expr.substr(beg + 1, lbeg - beg)));
		if (oper == '+')
			expr.replace(lbeg, lend - lbeg + 1, (n1 + n2).toString());
		else
			expr.replace(lbeg, lend - lbeg + 1, (n1 - n2).toString());
	}
	return (expr);

}

int main(int ac, char **av) {
	try{
		if (ac != 2)
			throw(0);
		std::string expr = av[1];
		size_t n = 0;
		while ((n = expr.find(" ", n) ) != std::string::npos)
			expr.replace( n, 1, "" );
		if (expr.find_first_not_of("1234567890-+/*().") != std::string::npos)
			throw(1);
		expr.insert(0, "!");
		expr.append("$");
		expr = eval_expr(expr);
		std::cout << expr.substr(1, expr.length() - 2) << std::endl;
	} catch (int i)
	{
		if (i == 0)
			std::cout << "Error in amount of params" << std::endl;
		else if (i == 1)
			std::cout << "Error in string" << std::endl;
		else if (i == 2)
			std::cout << "Error with ()" << std::endl;
		else if (i == 3)
			std::cout << "Error with numbers" << std::endl;
		return (1);
	}
	return 0;
}
