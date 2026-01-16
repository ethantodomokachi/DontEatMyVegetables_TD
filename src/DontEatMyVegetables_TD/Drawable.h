#pragma once
#include <SDL_image.h>

class Drawable
{
public:
	virtual void Draw(SDL_Renderer* renderer) = 0;
};

