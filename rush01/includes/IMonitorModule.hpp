#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class	IMonitorModule
{
	public:

		virtual int	update(void) = 0;//loops forever, after exit retuns:
		virtual	~IMonitorModule(void) {};
		//0 if time to exit
		//1 if we gotta go to graphical mode
		//2 if we gotta go to console mode

};

#endif
