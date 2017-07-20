#include "Ball.h"
#include "SpriteCodex.h"


Ball::Ball(float x, float y):
	Rect(x, y, 14.0f, 14.0f, {0,0,0}),
Dir(1,1)
{
}

void Ball::UpdatePos(float dt)
{
	center += Dir.GetNormalized()*dt*Speed;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

