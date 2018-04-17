#include <iostream>
#include "Monitor.hpp"
#include "TextMonitor.hpp"
#include "GraphicalMonitor.hpp"

Monitor::Monitor(std::string display):monitor(NULL)
{
	if (display == "console")
		monitor = new TextMonitor();
	else if (display == "gui")
		monitor = new GraphicalMonitor();
	else
		throw(std::invalid_argument("No known argument \"" + display + "\""));
}

void	Monitor::run(void)
{
	int	ret;
	GetData::getData().update();
	GetData::getData().updateTop();
	monitor->update();
	while ((ret = monitor->update()))//change method's name to run
	{
	// std::cout<<"Potatos 2"<<std::endl;
		if (monitor)
			delete monitor;
		if (ret == 1)
			monitor = new GraphicalMonitor();
		if (ret == 2)
			monitor = new TextMonitor();
		GetData::getData().update();
		GetData::getData().updateTop();
	}

}

Monitor::~Monitor(void)
{
	if (monitor)
		delete monitor;
}
