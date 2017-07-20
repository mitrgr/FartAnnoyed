#include "Wall.h"



Wall::Wall(float x, float y, const float h, const float w):
	Rect(x, y, h, w, {255,255,255})
{

}

void Wall::Draw(Graphics& gfx) const
{
	gfx.DrawBox(int(GetUL().x), int(GetUL().y) ,int( GetDR().x), int(GetDR().y), Col);
}



