#include "Engine.h"

void Engine::initialize()
{
	_crono = new Character();
	SDL_Init(SDL_INIT_EVERYTHING);
	_screen = SDL_SetVideoMode(640,480,0,SDL_HWSURFACE | SDL_DOUBLEBUF);	
	_running = true;
	_crono->load();
	_crono->update(_screen,0,310,210,125,0,36,30);
	_keystate = SDL_GetKeyState(NULL);
}

void Engine::execute()
{
	initialize();
	while(_running)
	{

		while(SDL_PollEvent(&_event))
		{
			checkEvent(&_event);
			
		}
		
		render(_keystate);
		

	}
	
	cleanUp();
}

void Engine::cleanUp()
{
	if (_crono)
		delete _crono;
	SDL_FreeSurface(_screen);
	SDL_Quit();
}

void Engine::render(Uint8* _keystate)
{	
	_crono->update(_screen,_keystate,310,210,240,600,36,30);	
	
}

void Engine::checkEvent(SDL_Event* _event)
{
	if(_event->type == SDL_QUIT)
		_running = false;
	

}

