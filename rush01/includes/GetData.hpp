#ifndef GETDATA_HPP
#define GETDATA_HPP
#include <string>
#include <vector>
#include "structures.hpp"

class	GetData
{
	public:

		const std::string	&getHostname(void) const;
		const std::string	&getUsername(void) const;
		const std::string	&getTime(void) const;
		const dataModule	&getRAM(void) const;
		const dataModule	&getLOAD(void) const;
		const dataModule	&getCPU(void) const;
		const osInfo		&getOsInfo(void) const;
		const std::vector<std::string>		&getOtherInfo(void) const;


		static	GetData		&getData(void);

		void	update(void);
		void	updateTop(void);

	private:
		
		std::string	hostname;
		std::string	username;
		std::string	time;
		dataModule	RAM;
		dataModule	LOAD;
		dataModule	CPU;
		osInfo	os;
		std::vector<std::string>	otherInfo;

		GetData(void);
		GetData(const GetData &);
		GetData	&operator=(const GetData &);
		~GetData(void);

		std::vector<std::string>	getTop(void) const;
};

#endif

