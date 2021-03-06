#include "Animation.h"

Animation::Animation()
{
	_maxFrames = 0;
	_frame = 0;
	_frameCap = 130;
	
}

void Animation::animate()
{
	static int timeDifference = 0;

	if ((SDL_GetTicks()-timeDifference) < _frameCap)
		return;
	
	if (_frame < _maxFrames)
	{
		_frame++;
	}
	else _frame = 0;

	timeDifference = SDL_GetTicks();
}

void Animation::setMaxFrames(int max)
{
	_maxFrames = max;
}

void Animation::setFrame(int frame)
{
	_frame = frame;
}

void Animation::setFrameCap(int cap)
{
	_frameCap = cap;

}

int Animation::getFrame() const
{
	return _frame;
}
