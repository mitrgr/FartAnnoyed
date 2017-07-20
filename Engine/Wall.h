#pragma once
#include "Rect.h"
#include "Graphics.h"

class Wall: public Rect
{
public:
	Wall(float x, float y, const float h, const float w);
	
	void Draw(Graphics& gfx) const;

	bool Wall::OutsideLeft(const Rect& R) const;
	
	bool Wall::OutsideRight(const Rect& R) const;
	
	bool Wall::OutsideTop(const Rect& R) const;
	
	bool Wall::OutsideBottom(const Rect& R) const;
	

private:


};

