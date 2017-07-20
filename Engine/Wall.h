#pragma once
#include "Rect.h"
#include "Graphics.h"

class Wall: public Rect
{
public:
	Wall(float x, float y, const float h, const float w);
	
	void Draw(Graphics& gfx) const;


};

