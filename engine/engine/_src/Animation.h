#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "SDL.h"

class Animation
{
	public:
		Animation();
		int _maxFrames;
		int _frame;		
		int _frameCap;
		void setMaxFrames(int);
		void setFrame(int);
		void setFrameCap(int);
		int getFrame() const;
		void animate();		
};

#endif
