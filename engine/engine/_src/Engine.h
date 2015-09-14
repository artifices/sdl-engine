#ifndef ENGINE_H_
#define ENGINE_H_

#include "SDL.h"
#include "Entity.h"
#include "Character.h"

class Engine
{
	public:
		void initialize();
		void execute();
		void checkEvent(SDL_Event*);		
		void render(Uint8*);
		void cleanUp();		

	protected:
		SDL_Surface* _screen;
		SDL_Event _event;
		Entity* _crono;
		bool _running;
		Uint8* _keystate;
};

#endif