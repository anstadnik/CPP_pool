#ifndef MONITOR_HPP
#define MONITOR_HPP
#include <string>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "GetData.hpp"
#include "structures.hpp"

class	Monitor: public IMonitorDisplay
{
	public:
		Monitor(std::string	display);//graphic, text etc
		void	run(void);
		~Monitor(void);

	private:

		Monitor(void);
		Monitor(const Monitor &);
		Monitor	&operator=(const Monitor &);
		IMonitorModule	*monitor;
};

#endif

