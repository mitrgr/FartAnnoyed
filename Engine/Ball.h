#include "Rect.h"
#include "Graphics.h"


#pragma once

class Ball: public Rect
{
public:
	Ball(float x, float y, Color C);

	
	void UpdatePos();
	void Draw(Graphics gfx) const;



private:
	Vec2 Dir;

	
};

