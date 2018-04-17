#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <exception>

template<typename T>
typename T::const_iterator	easyfind(T cont, int value)
{
	typename T::const_iterator	ret = std::find(cont.begin(), cont.end(), value);
	if (ret == cont.end())
		throw (std::invalid_argument("Not found"));
	return (ret);
}

#endif
