#include "Entity.h"


void Entity::load(string filename)
{
	
	char* charTemp = new char[filename.size()+1];
	for (int i = 0; i < filename.size()+1; i++)
		charTemp[i] = filename[i];

	SDL_Surface* temp;
	temp = IMG_Load(charTemp);
	_sprite = SDL_DisplayFormatAlpha(temp);
	SDL_FreeSurface(temp);
	delete [] charTemp;
}