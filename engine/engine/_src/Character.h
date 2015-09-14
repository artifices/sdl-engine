#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Entity.h"
#include "Animation.h"

class Character : public Entity
{
	public:
		Character();
		~Character();
		virtual void load(string);
		bool checkCollision(Entity*);
		bool checkBoundary();
		virtual void draw(SDL_Surface*, SDL_Rect, SDL_Rect);
		virtual void update(SDL_Surface*, Uint8*,Entity*,double, double, int, int, int, int);
		virtual void moveRight(SDL_Rect&,SDL_Rect&);
		virtual void moveLeft(SDL_Rect&,SDL_Rect&);
		virtual void moveUp(SDL_Rect&,SDL_Rect&);
		virtual void moveDown(SDL_Rect&,SDL_Rect&);		
		virtual void runRight(SDL_Rect&,SDL_Rect&);	
		virtual void runLeft(SDL_Rect&,SDL_Rect&);
		virtual void runUp(SDL_Rect&,SDL_Rect&);
		virtual void runDown(SDL_Rect&,SDL_Rect&);
	protected:
		Animation anim;		
		
		
};

#endif