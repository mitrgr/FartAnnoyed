#include "Pad.h"
#include "Colors.h"


Pad::Pad(float x, float y):
	Rect(x, y, Height, Width, { (0x80u, 0x80u, 0x80u) })
{
}




void Pad::Update(Keyboard & kbd, float dt)
{
	if (kbd.KeyIsPressed(0x25)) {
		center.x -= Speed*dt;
	}
	if (kbd.KeyIsPressed(0x27)) {
		center.x += Speed*dt;
	}
}

void Pad::KeepIn(bool Right, bool Left)
{
	if (Right) {
		center.x = maxx - Width / 2;
	}
	if (Left) {
		center.x = minx + Width / 2;
	}
}

void Pad::Draw(Graphics & gfx) const
{
	gfx.DrawRect((int)GetUL().x, (int)GetUL().y, (int)GetDR().x, (int)GetDR().y, Col);
}







bool Pad::HitBallLeft(const Rect& R) const 
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float BL = R.GetUL().x,   BC = R.GetCenter().y , BR = R.GetDR().x;
	return (BR >= PL && BC >= PT  && BC <= PB && BR < PR);

}

bool Pad::HitBallRight(const Rect& R) const
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float BL = R.GetUL().x, BR = R.GetDR().x, BC = R.GetCenter().y;
	return (BL <= PR && BC >= PT &&  BC <= PB && BL > PL);
}

bool Pad::HitBallBottom(const Rect& R ) const
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float  BT = R.GetUL().y, BB = R.GetDR().y, BC = R.GetCenter().x;
	return (BT <= PB && BC >= PL &&  BC <= PR && BT > PT);
}

bool Pad::HitBallTop(const Rect& R) const 
{
	float PT = GetUR().y, PB = GetDR().y, PL = GetUL().x, PR = GetDR().x;
	float BT = R.GetUL().y, BC = R.GetCenter().x, BB = R.GetDR().y;
	return (BB >= PT && BC >= PL && BC <= PR && BB < PB );
}