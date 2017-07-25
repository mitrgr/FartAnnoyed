#pragma once
#include "Ball.h"
class Hud
{
public:
	Hud();
	
	bool IsGameOver() const;
	void HitBottom(Ball & ball);
	void NewBall(Ball& ball) const;
	void NewGame(Ball & ball);
	bool IsBallStartet() const;
	void StartBall();

private:
	int startlives = 3;
	int Lives = startlives;
	bool isGameOver = false;
	bool BallIsStartet = false;
};

