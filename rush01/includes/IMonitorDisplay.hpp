#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

class	IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void) {};
		virtual	void	run(void) = 0;
};

#endif
