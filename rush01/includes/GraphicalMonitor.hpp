#ifndef GRAPHICALMONITOR_HPP
#define GRAPHICALMONITOR_HPP

#include "IMonitorModule.hpp"
#include "GetData.hpp"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <iostream>

class GraphicalMonitor : public IMonitorModule
{
	protected:
		int _width, _height, _margin, _linesCount;
		std::string _name;
		SDL_Window* _window;
		SDL_Surface* _screen;

		SDL_Surface* _textSurface;
		SDL_Texture* _textTexture;
		TTF_Font* 	_textFont;
		SDL_Color 	_textColor;
		SDL_Rect 	_textRect;
		SDL_Event 	_e;

		SDL_Rect 	_backgroundRect;
		Uint32 		_backgroundColor;
		Uint32 		_moduleColor;
		Uint32 		_headerColor;
		Uint32 		_bodyColor;
		Uint32 		_lineColor;
		typedef struct
		{
			SDL_Rect					background;
			SDL_Rect					header;
			SDL_Rect					body;
			std::vector<SDL_Rect> 		vectorLines;
			std::vector<int> 			dataVector;
			std::string					headerText;
			std::string					bodyText;

		} visualModule;
		std::vector<visualModule> _vectorModules;
		int 	_running;


	public:

		GraphicalMonitor();
		GraphicalMonitor& operator=(GraphicalMonitor const& copy);
		GraphicalMonitor(GraphicalMonitor const& copy);
		~GraphicalMonitor();
		int	update(void);
		std::string getName() const;
		void	updateGraphics();
		int		handleEvent(SDL_Event event);
		void	initModules();	
};

std::ostream& operator<<(std::ostream& o, GraphicalMonitor const& rhs);

#endif
