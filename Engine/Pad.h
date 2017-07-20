#pragma once

#include "Rect.h"
#include "Keyboard.h"
#include "Graphics.h"

class Pad : public Rect
{
public:
	Pad(float x, float y);

	void Update(Keyboard& kbd, float dt);
	void KeepIn(bool Right, bool Left);

	void Draw(Graphics& gfx) const;

	bool HitBallLeft(const Rect& R) const;
	bool HitBallRight(const Rect& R) const ;
	bool HitBallTop(const Rect& R) const;
	bool HitBallBottom(const Rect& R) const;

private:
	static constexpr float Height = 10.0f;
	static constexpr float Width = 100.0f;
	const float Speed = 60.0f;
	const float maxx = 600.0f , minx=200.0f;
};

