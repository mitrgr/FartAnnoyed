#include "Wall.h"



Wall::Wall(float x, float y, const float h, const float w):
	Rect(x, y, h, w, {255,255,255})
{

}

void Wall::Draw(Graphics& gfx) const
{
	gfx.DrawBox(int(GetUL().x), int(GetUL().y) ,int( GetDR().x), int(GetDR().y), Col);
}

bool Wall::OutsideLeft(const Rect& R) const 
{
	return R.GetDL().x <= GetDL().x;
}

bool Wall::OutsideRight(const Rect& R) const
{
	return R.GetDR().x >= GetDR().x;
}
bool Wall::OutsideTop(const Rect& R) const
{
	return R.GetUR().y <= GetUR().y;
}
bool Wall::OutsideBottom(const Rect& R) const
{
	return R.GetDR().y >= GetDR().y;
}


