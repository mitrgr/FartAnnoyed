#include "Ball.h"
#include "SpriteCodex.h"
#include <math.h>


Ball::Ball(float x, float y):
	Rect(x, y, 14.0f, 14.0f, {0,0,0}),
Dir(1,1)
{
	Speed = 120.0f;
}
Ball::Ball(float x, float y, const float s) :
	Rect(x, y, 14.0f, 14.0f, { 0,0,0 }),
	Dir(1, 1)
{
	Speed = s;
}
void Ball::ChangeDirY(bool cange)
{
	if (cange) {
		Dir.y *= -1;
	}	
}

void Ball::ChangeDirX(bool cange)
{
	if (cange) {
		Dir.x *= -1;
	}
}

void Ball::ChangeDirYPad(const Rect & pad)
{
	Dir.y = -1.0f/(5*(std::abs(center.x - pad.GetCenter().x)+2.0f)/pad.GetW());
	Speed = 120.0f + std::abs(center.x - pad.GetCenter().x)/2.0f;
}

void Ball::ChangeDirXPad(const Rect & pad)
{
	Dir.x *= -1.0f / (10.0f*(std::abs(center.y - pad.GetCenter().y) + 2.0f) / pad.GetW());
}

void Ball::NewPos(const float x, const float y)
{
	center.x = x;
	center.y = y;
}

void Ball::UpdatePos(float dt, const Rect& border)
{
	center += Dir.GetNormalized()*dt*Speed;

	if (GetUR().x > border.GetUR().x) {
		center -= Vec2(GetUR().x - border.GetUR().x, 0);
	}
	if (GetUR().y < border.GetUR().y) {
		center -= Vec2(0,GetUR().y - border.GetUR().y);
	}
	if (GetDL().y > border.GetDL().y) {
		center -= Vec2(0,GetDL().y - border.GetDL().y);
	}
	if (GetDL().x < border.GetDL().x) {
		center -= Vec2(GetDL().x - border.GetDL().x,0);
	}
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

