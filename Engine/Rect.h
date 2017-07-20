#include "Vec2.h"
#include "Colors.h"
#pragma once



class Rect
{
public:
	Rect( int x, int y, int H, int W, Color C);

	Vec2 GetCenter() const;
	const int GetH() const;
	const int GetW() const;
	const Vec2 GetUR() const;
	const Vec2 GetUL() const;
	const Vec2 GetDR() const;
	const Vec2 GetDL() const;
	const Color GetC() const;


private:
	Vec2 center;
	const int Height, Width;
	Color Col;
};

