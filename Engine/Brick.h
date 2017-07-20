#pragma once

#include "Rect.h"
#include "Graphics.h"

class Brick: public Rect
{
public:
	Brick();
	void init(float x, float y, Color C);

	void Draw(Graphics& gfx) const;

	bool GotHit();
	void Update(const Rect& R, bool& b);


	bool HitBallLeft(const Rect& R) const;
	bool HitBallRight(const Rect& R) const;
	bool HitBallTop(const Rect& R) const;
	bool HitBallBottom(const Rect& R) const;

	static constexpr float H = 25, W = 50;
private:
	
	bool hit = false;

};

