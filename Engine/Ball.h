#include "Rect.h"
#include "Graphics.h"


#pragma once

class Ball: public Rect
{
public:
	Ball(float x, float y);

	
	void UpdatePos(float dt);
	void Draw(Graphics& gfx) const;



private:
	Vec2 Dir;
	const float Speed = 60;
	
};

