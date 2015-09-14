#include "Entity.h"

void Entity::load()
{
	SDL_Surface* temp;
	temp = IMG_Load(_filename);
	_sprite = SDL_DisplayFormatAlpha(temp);
	SDL_FreeSurface(temp);
}