#include "Ball.h"
#include "SpriteCodex.h"


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

void Ball::UpdatePos(float dt)
{
	center += Dir.GetNormalized()*dt*Speed;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

