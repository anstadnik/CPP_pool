#include "../includes/TextMonitor.hpp"
#include "../includes/GetData.hpp"
#include <iostream>

TextMonitor::TextMonitor(){
	initscr();
	nodelay(stdscr, TRUE);
	noecho();
	/* cbreak(); */
	curs_set(0);
	getmaxyx(stdscr, this->_height, this->_width);
	/* cbreak(); */
}

TextMonitor::TextMonitor(int width, int height) : _width(width), 
	_height(height){
		initscr();
	}

TextMonitor::~TextMonitor(){
	endwin();
}

TextMonitor &	TextMonitor::operator=( TextMonitor const &rhs){
	if (this != &rhs){
		this->_height = rhs._height;
		this->_width = rhs._width;
	}
	return *this;
}
TextMonitor::TextMonitor(TextMonitor const& copy){
	*this = copy;
}

int	TextMonitor::update(void){
	while(true)
	{
		clear();
		GetData::getData().update();
		GetData::getData().updateTop();
		size_t	height = 0;
		height += 2;
		mvprintw(height,5,(GetData::getData().getUsername() + " " + GetData::getData().getHostname()).c_str());
		mvprintw(++height,5,GetData::getData().getTime().c_str());
		height += 2;
		mvprintw(height,5,(GetData::getData().getOsInfo().release + " " + GetData::getData().getOsInfo().release + " " + GetData::getData().getOsInfo().ICantComeUpWithAnAppropriateName).c_str());
		height += 2;
		height = drawModule(height, GetData::getData().getCPU());
		height = drawModule(height, GetData::getData().getRAM());
		height = drawModule(height, GetData::getData().getLOAD());
		for (size_t i = 0; i < GetData::getData().getOtherInfo().size(); i++)
			mvprintw(++height,5,GetData::getData().getOtherInfo()[i].c_str());
		border(0, 0, 0, 0, 0, 0, 0, 0);
		timeout(100);
		int _ch = getch();
		if (_ch == 27)
			return (0);
		if (_ch == '\n' || _ch == 'g')
			return (1);
		refresh();
	}
	return 0;
}

size_t	TextMonitor::drawModule(size_t offs, const dataModule & data)
{
	/* WINDOW * win = subwin(stdscr, module->getHeight(), module->getWidth(), module->getPosY(), module->getPosX()); */
	mvprintw(++offs,5,data.name.c_str());
	mvprintw(++offs,5,data.valDesc.c_str());
	if (data.name != "CPU")
	{
		for (size_t i = 0; i < data.text.size(); i++)
			mvprintw(++offs,5,(data.text[i]).c_str());
	}
	return (offs + 2);
}

int 	TextMonitor::getWidth(){
	return _width;
}

int 	TextMonitor::getHeight(){
	return _height;
}
