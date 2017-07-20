/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(300.0f, 200.0f),
	wall((float)(Graphics::ScreenWidth / 2), (float)(Graphics::ScreenHeight / 2), (float)(BoardH), (float)(BoardW)),
	pad(300.0f, 500.0f)
{
	const Color colors[4] = { {255,0,0}, {0,255,0}, {0,0,255}, {255,0,255} };
	int i = 0;
	for (int y = 0; y < nPerCol; y++) {
		const Color C = colors[y];
		for (int x = 0; x < nPerRow; x++) {
			bricks[i].init( (float) ((wall.GetUL().x + (Brick::W / 2.0f)+x*(Brick::W))) ,(float) ( (wall.GetUL().y + (Brick::H / 2.0f)+y*(Brick::H))), C);
			i++;
		}
	}

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	Updatecount += dt;
	pad.Update(wnd.kbd, dt);
	pad.KeepIn(wall.OutsideRight(pad), wall.OutsideLeft(pad));

	ball.UpdatePos(dt, wall);
	
	ball.ChangeDirX((wall.OutsideLeft(ball) || wall.OutsideRight(ball)));
	ball.ChangeDirY((wall.OutsideTop(ball) || wall.OutsideBottom(ball)));
	if (Updatecount >= DelayTimer) {
		canBeChanged = true;
		Updatecount = DelayTimer;
	}

	if (canBeChanged && ((pad.HitBallBottom(ball) || pad.HitBallTop(ball)))) {
		ball.ChangeDirY((pad.HitBallBottom(ball) || pad.HitBallTop(ball)));
		canBeChanged = false;
		Updatecount = 0;
	}
	if (canBeChanged && (pad.HitBallLeft(ball) || pad.HitBallRight(ball))){
		ball.ChangeDirX((pad.HitBallLeft(ball) || pad.HitBallRight(ball)));
		canBeChanged = false;
		Updatecount = 0;
	}
	bool b;
	for (Brick & i : bricks) {
		if (!i.GotHit()) {
			i.Update(ball, b);

			if (canBeChanged && ((i.HitBallBottom(ball) || i.HitBallTop(ball)))) {
				ball.ChangeDirY((i.HitBallBottom(ball) || i.HitBallTop(ball)));
				canBeChanged = false;
				Updatecount = 0;
			}
			if (canBeChanged && (i.HitBallLeft(ball) || i.HitBallRight(ball))) {
				ball.ChangeDirX((i.HitBallLeft(ball) || i.HitBallRight(ball)));
				canBeChanged = false;
				Updatecount = 0;
			}
		}
	}

}

void Game::ComposeFrame()
{
	for (Brick & i : bricks) {
		i.Draw(gfx);
	}
	ball.Draw(gfx);
	pad.Draw(gfx);
	wall.Draw(gfx);


}
