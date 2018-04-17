#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <time.h>

Logger::Logger(std::string file)
{
	this->file = file;
}


std::string	Logger::makeLogEntry(std::string message)
{
	std::time_t t = std::time(nullptr);
	char mbstr[100];
	std::strftime(mbstr, sizeof(mbstr), "[%Y%m%d_%H%M%S]", std::localtime(&t));
	return (std::string(mbstr).append(" " + message));
}

void	Logger::log(std::string const & dest, std::string const & message)
{
	std::string	sarr[2] = {"Console", "File"};
	void (Logger::*farr[2])(std::string str) =
	{&Logger::logToConsole, &Logger::logToFile};
	for (int i = 0; i < 2; i++)
	{
		/* std::cout << dest << ":" << sarr[i] << (dest == sarr[i]) << std::endl << std::endl; */
		if (sarr[i] == dest)
		{
			(this->*farr[i])(message);
			return ;
		}
	}
	std::cout << "Error dest" << std::endl;
}

void	Logger::logToConsole(std::string str)
{
	std::cout << this->makeLogEntry(str) << std::endl;
}

void	Logger::logToFile(std::string str)
{
	std::ofstream o;
	
	o.open(this->file, std::ofstream::out | std::ofstream::app);
	o << this->makeLogEntry(str) << std::endl; 
}
