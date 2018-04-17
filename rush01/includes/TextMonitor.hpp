#ifndef TEXTMONITOR_HPP
#define TEXTMONITOR_HPP

#include "IMonitorModule.hpp"
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <ostream>
#include "structures.hpp"

class TextMonitor : public IMonitorModule
{
	protected:
		int 	_width, _height;

	public:
		TextMonitor();
		~TextMonitor();

		int	update(void);
		void	initScreen();

		int 	getWidth();
		int 	getHeight();

	private:

		TextMonitor(int width, int height);
		TextMonitor& operator=(TextMonitor const& copy);
		TextMonitor(TextMonitor const& copy);
		size_t	drawModule(size_t offs, const dataModule &);
};

std::ostream& operator<<(std::ostream& o, TextMonitor const& rhs);

#endif
