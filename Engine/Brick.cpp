#include "Brick.h"
Brick::Brick() : Rect(0, 0, H, W, { 0,0,0 }) 
{

}

void Brick::init(float x, float y, Color C)
{
	center.x = x;
	center.y = y;
	Col = C;
}

void Brick::Draw(Graphics& gfx) const
{
	if (!hit) {
		gfx.DrawRect((int)GetUL().x+1, (int)GetUL().y+1, (int)GetDR().x-1, (int)GetDR().y-1, GetC());
	}
}

bool Brick::GotHit()
{
	return hit;
}

void Brick::Update(const Rect & R, bool& b)
{
	if (!hit) {
		hit = HitBallLeft(R);
		b = true;
	}
	if (!hit) {
		hit = HitBallRight(R);
		b = true;
	}
	if (!hit) {
		hit = HitBallTop(R);
		b = false;
	}
	if (!hit) {
		hit = HitBallBottom(R);
		b = false;
	}
}


bool Brick::HitBallLeft(const Rect& R) const
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float BL = R.GetUL().x, BC = R.GetCenter().y, BR = R.GetDR().x;
	return (BR >= PL && BC >= PT  && BC <= PB && BR < PR);

}

bool Brick::HitBallRight(const Rect& R) const
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float BL = R.GetUL().x, BR = R.GetDR().x, BC = R.GetCenter().y;
	return (BL <= PR && BC >= PT &&  BC <= PB && BL > PL);
}

bool Brick::HitBallBottom(const Rect& R) const
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float  BT = R.GetUL().y, BB = R.GetDR().y, BC = R.GetCenter().x;
	return (BT <= PB && BC >= PL &&  BC <= PR && BT > PT);
}

bool Brick::HitBallTop(const Rect& R) const
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float BT = R.GetUL().y, BC = R.GetCenter().x, BB = R.GetDR().y;
	return (BB >= PT && BC >= PL && BC <= PR && BB < PB);
}