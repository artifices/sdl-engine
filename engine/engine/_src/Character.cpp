#include "Character.h"


Character::Character()
{
	_filename = "";
	_sprite = NULL;
}

Character::~Character()
{
	if (_sprite)
		SDL_FreeSurface(_sprite);	
}

void Character::load(string filename)
{
	_filename = filename;
	Entity::load(_filename);	
}

void Character::draw(SDL_Surface* _screen, SDL_Rect source, SDL_Rect destination)
{    
	
	SDL_BlitSurface(_sprite,&source,_screen,&destination);
	
	
}

void Character::update(SDL_Surface* screen,Uint8* keystate, Entity* other, double destX, double destY, int srcX, int srcY, int srcHeight, int srcWidth)
{
	SDL_Surface* message = IMG_Load("jeje.png");
	bool collision = false;
	if (!keystate)
	{
		_destination.x = destX;
		_destination.y = destY;
		_source.x = srcX;
		_source.y = srcY;
		_source.h = srcHeight;
		_source.w = srcWidth;
	}
	if (keystate)
	{
		
		if(keystate[SDLK_a])
			{
				
				SDL_BlitSurface(message, NULL, screen,NULL);

			}

			if((keystate[SDLK_SPACE]) && (keystate[SDLK_RIGHT]))
			{
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					runRight(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
				{
					_destination.x -= 2;
					collision = true;
				}
				
				
			}
			else if(keystate[SDLK_RIGHT])
			{
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					moveRight(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
				{
					_destination.x -= 1;
					collision = true;
				}
				
				
				
			}
		
		
		
			if((keystate[SDLK_SPACE]) && (keystate[SDLK_LEFT]))
			{
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					runLeft(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
					_destination.x += 2;
				
				
			}
			else if(keystate[SDLK_LEFT])
			{
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					moveLeft(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
					_destination.x += 1;
				
				
			}
	

			if((keystate[SDLK_SPACE]) && (keystate[SDLK_UP]))
			{
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					runUp(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
					_destination.y += 2;
			}
			else if(keystate[SDLK_UP])
			{	
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					moveUp(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
					_destination.y += 1;
			}
		
		
			if((keystate[SDLK_SPACE]) && (keystate[SDLK_DOWN]))
			{
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					runDown(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
					_destination.y -= 2;
			}
			else if(keystate[SDLK_DOWN])
			{	
				if ((checkCollision(other)== false) && (checkBoundary()== false))
					moveDown(_source,_destination);
				if ((checkCollision(other)== true) || (checkBoundary()== true))
					_destination.y -= 1;
			}
			
		

	
	}
	
	draw(screen,_source,_destination);	
	SDL_FreeSurface(message);

}

void Character::moveRight(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(5);
	anim.animate();

	SDL_Delay(6);
	if (destination.x < 620)
	{
		destination.x += 1;
		source.x = 242;
		source.y = (anim.getFrame()*40)+600;
		source.h = 35;
		source.w = 23;
	}
}

void Character::moveLeft(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(5);
	anim.animate();
	
	SDL_Delay(6);
	if (destination.x > 0)
	{
		destination.x -= 1;
		source.x = 162;
		source.y = (anim.getFrame()*40)+600;
		source.h = 35;
		source.w = 23;
	}
}

void Character::moveUp(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(5);
	anim.animate();
	
	SDL_Delay(6);
	if (destination.y > 0)
	{
		destination.y -= 1;
		source.x = 205;
		source.y = (anim.getFrame()*40)+600;
		source.h = 35;
		source.w = 23;
	}
}

void Character::moveDown(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(5);
	anim.animate();
	
	SDL_Delay(6);
	if (destination.y < 445)
	{
		destination.y += 1;
		source.x = 125;
		source.y = (anim.getFrame()*40)+600;
		source.h = 35;
		source.w = 23;
	}
}

void Character::runRight(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(3);
	anim.setFrameCap(110);
	anim.animate();	

	SDL_Delay(8);
	if (destination.x < 610)
	{
		destination.x += 2;
		source.x = 240;	
		source.y = (anim.getFrame()*40)+800;
		source.h = 35;
		source.w = 30;
	}
}

void Character::runLeft(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(3);
	anim.setFrameCap(110);
	anim.animate();
	

	SDL_Delay(8);
	if (destination.x > 0)
	{
		destination.x -= 2;
		source.x = 160;
		source.y = (anim.getFrame()*40)+800;
		source.h = 35;
		source.w = 30;
		
	}
}

void Character::runUp(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(3);
	anim.setFrameCap(110);
	anim.animate();


	SDL_Delay(8);
	if (destination.y > 0)
	{
		destination.y -= 2;
		source.x = 205;
		source.y = (anim.getFrame()*40)+800;
		source.h = 35;
		source.w = 30;
	
	}
}

void Character::runDown(SDL_Rect& source, SDL_Rect& destination)
{
	anim.setMaxFrames(3);
	anim.setFrameCap(110);
	anim.animate();


	SDL_Delay(8);
	if (destination.y < 445)
	{
		destination.y += 2;
		source.x = 125;
		source.y = (anim.getFrame()*40)+800;
		source.h = 35;
		source.w = 30;

	}
}

bool Character::checkCollision(Entity* other)
{
	int width = 20;
	if (((_destination.x > other->_destination.x-width) && (_destination.x < other->_destination.x+width)) && ((_destination.y > other->_destination.y-30) && (_destination.y < other->_destination.y+30)))
		return true;
	else
		return false;

}

bool Character::checkBoundary()
{
	if (((_destination.x > 390 ) || (_destination.x < 214)) || ((_destination.y > 295) || (_destination.y < 193)))
		return true;
	else return false;

}