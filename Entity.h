#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


class Entity
{
	public:
		virtual void load(string);
		virtual void draw(SDL_Surface*, SDL_Rect, SDL_Rect)=0;
		virtual void update(SDL_Surface*, Uint8*,Entity*,double, double, int, int, int, int)=0;
	public:
		SDL_Surface* _sprite;		
		string _filename;
		SDL_Rect _destination;
		SDL_Rect _source;
};

#endif
