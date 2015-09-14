#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SDL.h"
#include "SDL_image.h"

class Entity
{
	public:
		virtual void load();
		virtual void draw(SDL_Surface*, SDL_Rect, SDL_Rect)=0;
		virtual void update(SDL_Surface*, Uint8*,double, double, int, int, int, int)=0;
	protected:
		SDL_Surface* _sprite;		
		char* _filename;
};

#endif
