#include "Wall.h"



Wall::Wall(float x, float y, const float h, const float w):
	Rect(x, y, h, w, {255,255,255})
{

}

void Wall::Draw(Graphics& gfx) const
{
	gfx.DrawBox(int(GetUL().x), int(GetUL().y) ,int( GetDR().x), int(GetDR().y), Col);
}

bool Wall::OutsideLeft(Rect R)
{
	return R.GetDL().x <= GetDL().x;
}

bool Wall::OutsideRight(Rect R)
{
	return R.GetDR().x >= GetDR().x;
}
bool Wall::OutsideTop(Rect R)
{
	return R.GetUR().y <= GetUR().y;
}
bool Wall::OutsideBottom(Rect R)
{
	return R.GetDR().y >= GetDR().y;
}


