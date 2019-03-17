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
#include "SpriteCodex.h"
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd), snek(Location{ 2,2 }), brd(gfx),e(time(0)), goal(e, brd, snek)
{
	
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
	if (isGameStarted) {
		if (!gameIsOver) {
			if (wnd.kbd.KeyIsPressed(VK_UP)) {
				delta_loc = { 0,-1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
				delta_loc = { 0,1 };

			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
				delta_loc = { -1,0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
				delta_loc = { 1,0 };
			}

			++snekmoveCounter;

			if (snekmoveCounter >= snekMovePeriod) {

				snekmoveCounter = 0;
				const Location next = snek.getSnekNextLoc(delta_loc);
				if (!brd.isInBoard(next) || snek.isInTileExceptEnd(next)) {
					gameIsOver = true;
				}
				else {
					if (next == goal.getLocation()) {
						snek.grow();

					}
					snek.move(delta_loc);

					if (next == goal.getLocation()) {
						goal.reSpawn(e, brd, snek);
					}


				}
			}
		}
	}
	else {
		isGameStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}



void Game::ComposeFrame()
{
	if (isGameStarted) {
		snek.draw(brd);
		goal.draw(brd);
		brd.drawBorder();
		if (gameIsOver) {
			SpriteCodex::DrawGameOver(350, 265, gfx);
		}
	}

else {
	SpriteCodex::DrawTitle(290, 225, gfx);
}

}