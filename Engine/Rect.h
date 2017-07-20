#include "Vec2.h"
#include "Colors.h"
#pragma once



class Rect
{
public:
	Rect( float x, float y, float H, float W, Color C);

	Vec2 GetCenter() const;
	const float GetH() const;
	const float GetW() const;
	const Vec2 GetUR() const;
	const Vec2 GetUL() const;
	const Vec2 GetDR() const;
	const Vec2 GetDL() const;
	const Color GetC() const;


protected:
	Vec2 center;
	const float Height, Width;
	Color Col;
};

