#include "GraphicalMonitor.hpp"

GraphicalMonitor::GraphicalMonitor() : _width(1292), 
												  _height(500),
												  _margin(2),
												  _window(NULL),
												  _screen(NULL),
												  _textSurface(NULL),
												  _running(1)
												  {
	
	SDL_Init(SDL_INIT_VIDEO);
	_window =SDL_CreateWindow("Monitor",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								_width, _height,
								SDL_WINDOW_OPENGL);
	
	_screen = SDL_GetWindowSurface(_window);
	
	_backgroundColor = SDL_MapRGB(_screen->format,0xee,0xee,0xee);
	_moduleColor = SDL_MapRGB(_screen->format,0xaa,0xaa,0xaa);
	_headerColor = SDL_MapRGB(_screen->format,0xcc,0xcc,0xcc);
	_bodyColor = SDL_MapRGB(_screen->format,0x30,0x30,0x30);
	_lineColor = SDL_MapRGB(_screen->format,0x00,0xcc,0x00);
	_vectorModules.resize(3); // 3 boxes init
	
	_linesCount = (_width - _margin * 3) / (10 + _margin);
	for (int i = 0; i < static_cast<int>(_vectorModules.size()); i++){
		_vectorModules[i].vectorLines.resize(_linesCount);
		_vectorModules[i].dataVector.resize(_linesCount);
	}
	TTF_Init();
	_textColor.r = 0; _textColor.g = 0; _textColor.b = 0;
	_textFont = TTF_OpenFont("/Library/Fonts/Arial.ttf", 16);
}

GraphicalMonitor::~GraphicalMonitor(){
	TTF_CloseFont(_textFont);
	TTF_Quit();

	SDL_FreeSurface(_screen);
	SDL_FreeSurface(_textSurface);
	SDL_DestroyWindow(_window);
	SDL_Quit();

}

GraphicalMonitor &	GraphicalMonitor::operator=( GraphicalMonitor const &rhs){
	if (this != &rhs){
		this->_height = rhs._height;
		this->_width = rhs._width;
	}
	return *this;
}
GraphicalMonitor::GraphicalMonitor(GraphicalMonitor const& copy){
	*this = copy;
}

int GraphicalMonitor::update(void){
	while(this->_running == 1) {
		SDL_PollEvent(&_e);
		this->_running = handleEvent(_e);
		updateGraphics();
	}
	return this->_running;
}

void	GraphicalMonitor::updateGraphics(){
	GetData::getData().update();
	GetData::getData().updateTop();
	_vectorModules[0].dataVector.push_back(GetData::getData().getCPU().curVal);
	_vectorModules[0].dataVector.erase(_vectorModules[0].dataVector.begin());

	_vectorModules[1].dataVector.push_back(GetData::getData().getRAM().curVal);
	_vectorModules[1].dataVector.erase(_vectorModules[1].dataVector.begin());

	_vectorModules[2].dataVector.push_back(GetData::getData().getLOAD().curVal);
	_vectorModules[2].dataVector.erase(_vectorModules[2].dataVector.begin());
	initModules();
	SDL_FillRect( _screen, NULL, _backgroundColor);
	for (int i = 0; i < static_cast<int>(_vectorModules.size()); i++){
		SDL_FillRect( _screen, &_vectorModules[i].background, _moduleColor);
		SDL_FillRect( _screen, &_vectorModules[i].header, _headerColor);
		SDL_FillRect( _screen, &_vectorModules[i].body, _bodyColor);
		switch (i){
			case 0 :{
				_textSurface = TTF_RenderText_Solid(_textFont, (GetData::getData().getCPU().name + " " + GetData::getData().getCPU().valDesc).c_str(), _textColor);
				break;
			}
			case 1 :{
				_textSurface = TTF_RenderText_Solid(_textFont, (GetData::getData().getRAM().name + " " + GetData::getData().getRAM().valDesc).c_str(), _textColor);	
				break;
			}
			case 2 :{
				_textSurface = TTF_RenderText_Solid(_textFont, (GetData::getData().getLOAD().name + " " + GetData::getData().getLOAD().valDesc).c_str(), _textColor);
				break;
			}
		}
		SDL_BlitSurface(_textSurface, NULL, _screen, &_vectorModules[i].header);
		
	 _textRect.x = _margin;
	 _textRect.y = 415;
	 _textRect.w = _width - _margin;
	 _textRect.h = 200;

		_textSurface = TTF_RenderText_Solid(_textFont, GetData::getData().getHostname().c_str(), _textColor);
		SDL_BlitSurface(_textSurface, NULL, _screen, &_textRect);
		 _textRect.y = 435;
		_textSurface = TTF_RenderText_Solid(_textFont, GetData::getData().getUsername().c_str() , _textColor);
		SDL_BlitSurface(_textSurface, NULL, _screen, &_textRect);
		_textRect.y = 455;
		_textSurface = TTF_RenderText_Solid(_textFont, GetData::getData().getTime().c_str(), _textColor);
		SDL_BlitSurface(_textSurface, NULL, _screen, &_textRect);

		for (int j = 0; j < _linesCount; j++){
			SDL_FillRect( _screen, &_vectorModules[i].vectorLines[j], _lineColor);
		}
	}
	SDL_UpdateWindowSurface(_window);
}

int	GraphicalMonitor::handleEvent(SDL_Event event){
	switch(event.type) {
		case SDL_QUIT: { 
			return 0;
		}
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
				case SDLK_t: { 
					return 2;
				}
			}
		}
	return 1;
}

void	GraphicalMonitor::initModules(){
	for (int i = 0; i < static_cast<int>(_vectorModules.size()); i++){
		_vectorModules[i].background.x =  _margin;
		_vectorModules[i].background.y = 135 * i + _margin; 
		_vectorModules[i].background.w = _width - _margin;
		_vectorModules[i].background.h = 135 - _margin;

		_vectorModules[i].header.x = _vectorModules[i].background.x + _margin;
		_vectorModules[i].header.y = _vectorModules[i].background.y + _margin; 
		_vectorModules[i].header.w = _vectorModules[i].background.w - _margin  * 2;
		_vectorModules[i].header.h = 25;

		_vectorModules[i].body.x = _vectorModules[i].background.x + _margin;
		_vectorModules[i].body.y = _vectorModules[i].header.y + _vectorModules[i].header.h + _margin; 
		_vectorModules[i].body.w = _vectorModules[i].background.w - _margin  * 2;
		_vectorModules[i].body.h = _vectorModules[i].background.h - _vectorModules[i].header.h - _margin * 3;		

		for (int j = 0; j < _linesCount; j++)
		{
			_vectorModules[i].vectorLines[j].x = _vectorModules[i].body.x + _margin + j * (10 + _margin);
			_vectorModules[i].vectorLines[j].y = _vectorModules[i].body.y + _margin + (_vectorModules[i].body.h - _margin * 2 - _vectorModules[i].dataVector[j]); 
			_vectorModules[i].vectorLines[j].w = 10;
			_vectorModules[i].vectorLines[j].h = _vectorModules[i].dataVector[j]; //data is random int
		}
	}
}
