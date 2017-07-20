#include "Rect.h"
#include "Graphics.h"


#pragma once

class Ball: public Rect
{
public:
	Ball(float x, float y);
	Ball(float x, float y, const float s);
	
	void ChangeDirY(bool cange);
	void ChangeDirX(bool cange);

	void UpdatePos(float dt);
	void Draw(Graphics& gfx) const;

private:
	Vec2 Dir;
	float Speed;
	
};

