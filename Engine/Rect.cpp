#include "Rect.h"

Rect::Rect(float x, float y, const float H, const float W, Color C):
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

const float Rect::GetH() const
{
	return Height;
}

const float Rect::GetW() const
{
	return Width;
}

const Vec2 Rect::GetUR() const
{
	return this->center + Vec2(Width/2.0f,-Height/2.0f);
}

const Vec2 Rect::GetUL() const
{
	return this->center + Vec2(-Width / 2.0f, -Height / 2.0f);
}

const Vec2 Rect::GetDR() const
{
	return this->center + Vec2(Width / 2.0f, Height / 2.0f);
}

const Vec2 Rect::GetDL() const
{
	return this->center + Vec2(-Width / 2.0f, Height / 2.0f);
}

const Color Rect::GetC() const
{
	return Col;
}

