/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:18:55 by astadnik          #+#    #+#             */
/*   Updated: 2018/04/11 20:25:01 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(int e)
{
	switch (e)
	{
		case 1:
			std::cout << "Wrong amount of parameters" << std::endl;
			break;
		case 2:
			std::cout << "Invalid argument" << std::endl;
			break;
		case 3:
			std::cout << "Out of range" << std::endl;
			break;
	}
}

void	print(char n)
{
	std::cout << "char: '" << n << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f"  << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void	print(int n)
{
	if (isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f"  << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void	print(float n)
{
	if (isfinite(n))
	{
		if (isprint(n))
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::lowest())
			std::cout << "int: Non displayable" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(n) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f"  << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void	print(double n)
{
	if (isfinite(n))
	{
		if (isprint(n))
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::lowest())
			std::cout << "int: Non displayable" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(n) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	if ((n > std::numeric_limits<float>::max() || n < std::numeric_limits<float>::lowest()) && isfinite(n))
		std::cout << "float: Non displayable" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(n) << std::endl;
}

void	check(std::string s)
{
	size_t	p;

	if (s[s.length() - 1] == 'f')
	{
		bool	e = false;
		float	n;
		try
		{
			n = std::stof(s, &p);
		}
		catch (std::out_of_range err)
		{
			if (p == s.length() - 1)
				throw(3);
		}
		catch (std::invalid_argument err)
		{
			e = true;
		}
		if (p == s.length() - 1 && !e)
		{
			print(n);
			return ;
		}
	}
	{
		bool	e = false;
		int	n;
		try
		{
			n = std::stoi(s, &p);
		}
		catch (std::out_of_range err)
		{
			if (p == s.length())
				throw(3);
		}
		catch (std::invalid_argument err)
		{
			e = true;
		}
		if (p == s.length() && !e)
		{
			print(n);
			return ;
		}
	}
	{
		bool	e = false;
		double	n;
		try
		{
			n = std::stod(s, &p);
		}
		catch (std::out_of_range err)
		{
			if (p == s.length())
				throw(3);
		}
		catch (std::invalid_argument err)
		{
			e = true;
		}
		if (p == s.length() && !e)
		{
			print(n);
			return ;
		}
	}
	if (isprint(s[0]) && !s[1])
		print(s[0]);
	throw(2);
}

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw(1);
		check(av[1]);
	}
	catch (int e)
	{
		error(e);
		return (1);
	}
	return (0);
}
