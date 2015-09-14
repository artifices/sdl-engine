#include "Engine.h"
#include <iostream>
using namespace std;

void Engine::initialize()
{
	
	_crono = new Character();
	_gaspar = new Character();
	SDL_Init(SDL_INIT_EVERYTHING);
	_screen = SDL_SetVideoMode(640,480,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Reminiscence Engine", 0);
	_running = true;
	_crono->load("crono.png");
	_crono->update(_screen,0,0,380,210,125,0,36,30);


	_gaspar->load("gaspar.png");
	_gaspar->update(_screen,0,0,200,200,55,0,40,20);
	_keystate = SDL_GetKeyState(NULL);
	
}

void Engine::execute()
{
	cout << "FUCCCK MEEEEEEEEEEEE!!!!!";
	initialize();	
	while(_running)
	{

		while(SDL_PollEvent(&_event))
		{
			checkEvent(&_event);
			//SDL_Delay(100);
		}
		
		render(_keystate);
		
	
	}
	
	cleanUp();
	
}

void Engine::cleanUp()
{
	if (_crono)
		delete _crono;
	if (_gaspar)
		delete _gaspar;
	SDL_FreeSurface(_screen);
	SDL_FreeSurface(map);
	SDL_Quit();
}

void Engine::render(Uint8* _keystate)
{	

	SDL_Rect offset;
	offset.x = 200;
	offset.y = 150;
	map = IMG_Load("house.png");
	SDL_FillRect(_screen,NULL,0x000000);
	SDL_BlitSurface(map, NULL, _screen,&offset);
	_gaspar->update(_screen,0,0,385,279,55,0,40,20);
	//SDL_Flip(_screen);	

	_crono->update(_screen,_keystate,_gaspar,380,210,240,600,36,30);
	SDL_Flip(_screen);
	
	
	
	
}

void Engine::checkEvent(SDL_Event* _event)
{
	if(_event->type == SDL_QUIT)
		_running = false;
	

}

