#pragma once
#include "Rect.h"
#include "Graphics.h"

class Wall: public Rect
{
public:
	Wall(float x, float y, const float h, const float w);
	
	void Draw(Graphics& gfx) const;

	bool Wall::OutsideLeft(Rect R);
	
	bool Wall::OutsideRight(Rect R);
	
	bool Wall::OutsideTop(Rect R);
	
	bool Wall::OutsideBottom(Rect R);
	

private:


};

