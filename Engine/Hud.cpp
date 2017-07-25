#include "Hud.h"



Hud::Hud()
{
}

bool Hud::IsGameOver() const
{
	return isGameOver;
}

void Hud::HitBottom(Ball & ball)
{
	Lives--;
	if(Lives==0){
		isGameOver = true;
	}else{
		NewBall(ball);
		BallIsStartet = false;
	}
}

void Hud::NewBall(Ball & ball) const
{
	ball.NewPos(300.0f, 200.0f);
}

void Hud::NewGame(Ball & ball)
{
	Lives = startlives+1;
	isGameOver = false;
}

bool Hud::IsBallStartet() const
{
	return BallIsStartet;
}

void Hud::StartBall()
{
	BallIsStartet = true;
}


