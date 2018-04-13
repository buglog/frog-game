/***************************	*************************************************************** 
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
	gfx(wnd)
	//starting with left side of frame, moving clockwise.
{
	level0.init(frog);
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
	//check if frog got stabbed by spikes
	if (!frog.stabbed)
	{
		frog.Update(wnd.kbd);
	}
	else if (death < pause)
	{
		++death;
	}
	else if (death >= pause)
	{
		death = 0;
		level0.init(frog);	
		frog.stabbed = false;
	}
	//level 0
	level0.level(frog, gfx);
}

void Game::ComposeFrame()
{
	if (!frog.stabbed)
	{
		frog.Walk(gfx);
	}
	else
	{
		frog.skull(gfx);
	}
	frame.init(200, 50, 750, 550);
	c.SetR(255);
	c.SetG(0);
	c.SetB(0);
	frame.draw(2,c,gfx);
}