#include "Rect.h"

Rect::Rect(int x, int y, const int H, const int W, Color C):
center(x,y),
Height(H),
Width(W),
Col(C)
{
}

Vec2 Rect::GetCenter() const
{
	return center;
}

const int Rect::GetH() const
{
	return Height;
}

const int Rect::GetW() const
{
	return Width;
}

const Vec2 Rect::GetUR() const
{
	return this->center + Vec2(Width/2,-Height/2);
}

const Vec2 Rect::GetUL() const
{
	return this->center + Vec2(-Width / 2, -Height / 2);
}

const Vec2 Rect::GetDR() const
{
	return this->center + Vec2(Width / 2, Height / 2);
}

const Vec2 Rect::GetDL() const
{
	return this->center + Vec2(-Width / 2, Height / 2);
}

const Color Rect::GetC() const
{
	return Col;
}

