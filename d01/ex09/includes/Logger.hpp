#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>

class	Logger
{
	public:

		Logger(std::string name);
		std::string	makeLogEntry(std::string message);
		void	log(std::string const & dest, std::string const & message);

	private:

		void	logToConsole(std::string str);
		void	logToFile(std::string str);
		std::string	file;

};

#endif
